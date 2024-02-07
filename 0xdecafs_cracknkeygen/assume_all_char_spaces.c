#include <stdio.h>

// printable chars
// [032, 127)

int calc_xor_sum(char* s, int l)
{
	int sum = 0;
	for (int i = 0; i < l; ++i)
		sum += s[i] ^ i;
	return sum;
}

int main() {
	char s[20];
	int i;
	for (i = 0; i < 19; ++i)
		s[i] = ' ';
	s[i] = '\0';

	for (i = 1; i < 19; ++i)
		printf("%d: %04X\n", i, calc_xor_sum(s, i));
	return 0;
}