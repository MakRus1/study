#include <iostream>
#include <cassert>
#include "factorial.h"

using namespace std;

int main ()
{
	int n;
	cout << "input number: ";
	assert (cin >> n);
	cout << factorial(n) << endl;
	return 0;
}
