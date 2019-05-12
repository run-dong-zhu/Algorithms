/*
 * main.c
 *
 *  Created on: May 10, 2019
 *      Author: zhurundong
 */


#include <stdio.h>
#include "mem_repr.h"

int main() {
	printf("%s \n", "Hello World");

	int n = 15;
	printf("%d \n", count_set_bits(n));

	n = 14;

	printf("%d \n", count_set_bits_map(n));

	int i = 0x01234567;
	show_mem_rep((char *)&i, sizeof(i));

	show_endian();

	return 0;
}
