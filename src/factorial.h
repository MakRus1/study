#include <cassert>
#include <cstdint>

int64_t factorial (int n)
{
	assert(n > 0 && n <= 20);
	int64_t res = 1;
	for (int i = 2; i <= n; ++i)
		res *= i;
	return res;
}
