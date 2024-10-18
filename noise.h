#ifndef noise_h
#define noise_h

#include <stdlib.h>
#include <stdio.h>

#define amplitude 0.05

void RangedRandDemo(int range_min, int range_max, int n);
void add_noise (double *radioactivity, int N);

#endif //noise_h