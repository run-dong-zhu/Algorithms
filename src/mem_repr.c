/*
 * mem_repr.c
 *
 *  Created on: May 10, 2019
 *      Author: zhurundong
 */


#include<stdio.h>

#include "mem_repr.h"

/**
 * @param n, unsigned int
 * @return total number of '1' in binary format of n
 */
unsigned int count_set_bits(unsigned int n) {
	unsigned int count = 0;
	while(n)
	{
		count += n & 1;
		n >>= 1;
	}
	return count;
}

// create a bits map from 0 to 15
int num_to_bits[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

/**
 * @param n, unsigned int
 * @return total number of '1' in binary format of n
 */
unsigned int count_set_bits_map(unsigned int n) {
	int nibble = 0;

	if(0 == n) {
		return num_to_bits[0];
	}

	nibble = n & 0xf;

	return num_to_bits[nibble] + count_set_bits_map(n >>= 4);
}

/**
 * @param start char *, n int
 * @return order of memory stores in Integer n
 */
void show_mem_rep(char *start, int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

/**
 * show the memory representation in your machine
 */
void show_endian() {
	unsigned int x = 1;
	char *c = (char *)&x;
	if(*c) {
		printf("%s", "little endian");
	}
	else {
		printf("%s", "big endian");
	}
}
