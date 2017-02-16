#include <stdio.h>
#define POLYNOMIAL 0x104c11db7UL
#define CRCPOLY2 0xEDB88320UL
#define CHAR_BIT 8

#define TARGET "aiueo"

unsigned long crc(int n, unsigned char c[]){
	int i,j;
	unsigned long r;

	r = 0xFFFFFFFFUL;
	for(i = 0; i < n; i++){
		r ^= c[i];
		printf("[%d  ]: 0x%lx\n",i, r);
		for (j=0;j<CHAR_BIT;j++)
		{		if(r & 1) 
				r = (r >> 1) ^ CRCPOLY2;
			else 
				r >>= 1;
		
			printf("[%d-%d]: 0x%lx\n",i,j, r);
		}
		printf("[%d-f]: 0x%lx\n",i, r);
	}
	return r ^ 0xFFFFFFFFUL;
}


int main(void){

printf("str = %s\n", TARGET);
printf("crc=0x%lu\n ", crc(5, TARGET));

}
