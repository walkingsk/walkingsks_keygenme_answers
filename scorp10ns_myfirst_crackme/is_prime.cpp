#include <iostream>
#include <cmath>

bool is_prime(int n)
{
	int r = (int)sqrt(n);
	for (int i = 2; i <= r; ++i)
	{
		if (n % i == 0)
			return 0;
	}
	
	return 1;
}

int main() {
	
	for (int i = 2; i < 600; ++i)
		if (is_prime(i))
			std::cout << i << ' ';
	return 0;
}