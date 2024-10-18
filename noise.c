#include "noise.h"

int RangedRandDemo(int range_min, int range_max)
{
    // Generate random numbers in the interval [range_min, range_max], inclusive.

    int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return r;
}

void add_noise (double *radioactivity, int N)
{
    for (int i = 0; i < N; i++)
    {
        radioactivity[i] += (RangedRandDemo(-1000, 1000)/1000) * amplitude;
    }
}