#include <cassert>
#include <iostream>
#include "../factorial.h"

using namespace std;

int main()
{
	assert(factorial(1) == 1);
	assert(factorial(5) == 120);
	cout << "All tests accepted" << endl;
	return 0;
}
