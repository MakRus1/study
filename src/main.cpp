#include <iostream>
#include <cassert>

using namespace std;

int64_t factorial (int n)
{
	int64_t res = 1;
	for (int i = 2; i <= n; ++i)
		res *= i;
	return res;
}

int main ()
{
	int n;
	cout << "input number: ";
	assert (cin >> n);
	assert(n > 0 && n <= 20);
	cout << factorial(n) << endl;
	return 0;
}
