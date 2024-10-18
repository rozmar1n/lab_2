#ifndef noise_h
#define noise_h

#include <stdlib.h>
#include <stdio.h>

#define amplitude 0.05

int RangedRandDemo(int range_min, int range_max);
void add_noise (double *radioactivity, int N);

#endif //noise_h