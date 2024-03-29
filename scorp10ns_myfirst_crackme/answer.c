#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
// printable chars
// [032, 127)

4 x [032, 127)

[128, 504]


2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293 307 311 313 317 331 337 347 349 353 359 367 373 379 383 389 397 401 409 419 421 431 433 439 443 449 457 461 463 467 479 487 491 499 503 509 521 523 541 547 557 563 569 571 577 587 593 599
*/
#define PROPER_PRIMES 65

int main() {
	// XXXX-XXXX-XXXX-XXXX
	char s[20];
	int a[] = { 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,\
		211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,\
		311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,\
		419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503 }; // 65 numbers

	int i_sumj[4];
	int a1, a2, a3, a4;
	int sum_avg;
	int sum_high;
	int range_high;

	s[19] = 0;
	s[4] = s[9] = s[14] = '-';

	srand(time(0));

	for (;;)
	{
		i_sumj[0] = rand() % PROPER_PRIMES;
		i_sumj[1] = rand() % PROPER_PRIMES;
		i_sumj[2] = rand() % PROPER_PRIMES;
		i_sumj[3] = rand() % PROPER_PRIMES;

		if (i_sumj[0] < i_sumj[1] && i_sumj[1] < i_sumj[2] && i_sumj[2] < i_sumj[3])
			break;
	}
	for (int i = 0; i < 4; ++i)
		printf("a[%d]: %d\n", i_sumj[i], a[i_sumj[i]]);

	for (int i = 0; i < 4; ++i)
	{
		sum_avg = a[i_sumj[i]] >> 2;
		sum_high = sum_avg + (sum_avg - 20) + (a[i_sumj[i]] % 4) + 1;
		if (sum_high > 127)
			sum_high = 127;

		range_high = sum_high - 0x20;
		
		for (;;) // [0x20, range_high)
		{
			a1 = rand() % range_high + 0x20;
			a2 = rand() % range_high + 0x20;
			a3 = rand() % range_high + 0x20;
			a4 = rand() % range_high + 0x20;

			if (a1 + a2 + a3 + a4 == a[i_sumj[i]])
			{
				printf("%d, %d, %d, %d\n", a1, a2, a3, a4);

				break;
			}
		}
		s[i * 5 + 0] = a1;
		s[i * 5 + 1] = a2;
		s[i * 5 + 2] = a3;
		s[i * 5 + 3] = a4;
	}

	printf("%s", s);

	return 0;
}