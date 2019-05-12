/*
 * mem_repr.h
 *
 *  Created on: May 10, 2019
 *      Author: zhurundong
 */

#ifndef SRC_MEM_REPR_H_
#define SRC_MEM_REPR_H_

#include <stdio.h>

unsigned int count_set_bits(unsigned int n);
unsigned int count_set_bits_map(unsigned int n);
void show_mem_rep(char *start, int n);
void show_endian();

#endif /* SRC_MEM_REPR_H_ */
