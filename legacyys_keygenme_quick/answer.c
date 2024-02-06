#include <stdio.h>

int main()
{
	char s[16];
	char *p = s;
	srand(time(0));
	
	*p++ = rand()%10 + '0';
	*p++ = rand()%10 + '0';
	*p++ = rand()%10 + '0';
	*p++ = rand()%10 + '0';
	*p++ = '-';
	
	// printable chars
	// [0x20, 127)
	*p++ = (rand()%107 + 0x20) & 0xFE;
	*p++ = (rand()%107 + 0x20) & 0xFE;
	*p++ = (rand()%107 + 0x20) & 0xFE;
	*p++ = (rand()%107 + 0x20) & 0xFE;
	*p++ = '-';
	
	*(unsigned int*)p = 0x544B3352;
	p += 5;
	*p = 0;
	
	printf(s);

	return 0;
}