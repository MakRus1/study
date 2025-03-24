#include <iostream>
#include <cassert>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "factorial.h"

using namespace std;

void handle_request(int client_socket)
{
	char buffer[1024];
	size_t bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
	if (bytes_received <= 0)
	{
		close(client_socket);
		return;
	}
	buffer[bytes_received] = '\0';

	string request(buffer);
	size_t query_start = request.find("?number=");
	if (query_start == string::npos)
	{
		string response = "HTTP/1.1 400 Bad Request\r\n";
		send(client_socket, response.c_str(), response.length(), 0);
		close(client_socket);
		return;
	}

	size_t number_start = query_start + 8;
	size_t number_end = request.find(" ", number_start);
	if (number_end == string::npos)
		number_end = request.length();

	string number_str = request.substr(number_start, number_end - number_start);

	int number;
	try
	{
		number = atoi(number_str.c_str());
	} catch (const exception& e)
	{
		string response = "HTTP/1.1 400 Bad Request\r\n";
		send(client_socket, response.c_str(), response.length(), 0);
		close(client_socket);
		return;
	}

	try
	{
		long long res = factorial(number);
		string json_response = "{\"factorial\": " + to_string(res) +  "}";
		string http_response = "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: " + to_string(json_response.length()) + "\r\n\r\n" + json_response + "\r\n";
		send(client_socket, http_response.c_str(), http_response.length(), 0);
	} catch (const exception& e)
	{
		string response = "HTTP/1.1 500 Internal Server Error\r\n";
		send(client_socket, response.c_str(), response.length(), 0);
	}

	close(client_socket);
}

int main ()
{
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1)
	{
		cerr << "Failed to create socket" << endl;
		return 1;
	}

	sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(8080);

	if (bind(server_socket, (sockaddr*)&server_address, sizeof(server_address)) < 0)
	{
		cerr << "Cannot connect socket with address" << endl;
		close(server_socket);
		return 1;
	}

	if (listen(server_socket, 5) < 0)
	{
		cerr << "Error socket listener" << endl;
		close(server_socket);
		return 1;
	}

	cout << "Server was started on port 8080" << endl;

	while (true)
	{
		sockaddr_in client_address;
		socklen_t client_address_size = sizeof(client_address);
		int client_socket = accept(server_socket, (sockaddr*)&client_address, &client_address_size);
		if (client_socket < 0)
		{
			cerr << "Failed connection" << endl;
			continue;
		}

		handle_request(client_socket);
	}

	close(server_socket);

	return 0;
}
