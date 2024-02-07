#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// now we only consider printable chars
// [0x20, 0x7F)

/*
* 
assume all characters are spaces, then the total string would be as long as possible

len  sum
1:  0020
2:  0041
3:  0063
4:  0086
5:  00AA
6:  00CF
7:  00F5
8:  011C
9:  0144
10: 016D
11: 0197
12: 01C2
13: 01EE
14: 021B
15: 0249
16: 0278
17: 02A8
18: 02D9


-> an array of 20 bytes is surely suitable
*/

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
	int sum = 0;
	int sum_left;
	int s_next_could_be = 0x999;

	srand(time(0));


	for (i = 0; i < 19;)
	{
		s[i] = rand() % ((s_next_could_be >= 0x7F) ? 0x5F : (s_next_could_be - 0x20)) + 0x20;
		sum += s[i] ^ i;
		sum_left = 0x27B - sum;
		s_next_could_be = sum_left ^ (i + 1);

#ifdef _DEBUG
		printf("i: %d\ts[i]:'%c'\tsum_left: %04X\ts_next_could_be: %04X\n", i, s[i], sum_left, s_next_could_be);
#endif
		// when s[i] ^ i > s[i] after the xor operation
		// in that case sum_left < 0
		if (sum_left < 0 || s_next_could_be < 0x20)
		{
			// s[i] is not generated properly, so redo
			sum -= s[i] ^ i;
			continue;
		}
		else if (s_next_could_be >= 0x7F)
		{
			++i;
		}
		else if (s_next_could_be < 0x40)
		{
		CHOOSE_THAT_NEXT_CHAR:
			s[++i] = s_next_could_be;
			s[++i] = '\0';
			break;
		}
		else// [0x40, 0x7F)
		{
			if (rand() % 2)
			{
				++i;
			}
			else
			{
				goto CHOOSE_THAT_NEXT_CHAR;
				/*
				s[++i] = s_next_could_be;
				s[++i] = '\0';
				break;
				*/
			}
		}
	}

	printf("%s\n", s);
#ifdef _DEBUG
	printf("i: %d\n", i);
	printf("%04X", calc_xor_sum(s, i));
#endif
	return 0;
}