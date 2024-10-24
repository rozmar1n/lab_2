#include <stdio.h>
#include <math.h>

double model(double* radioctivity, double* time, int N, double point)
{
    int i = 0;
    double summ = 0;
    for(i; i < N; i++)
    {
        summ += time[i] * exp( - time[i] / point ) * ( radioctivity[i] - exp( - time[i] / point ) );
    }
    return summ;
}
