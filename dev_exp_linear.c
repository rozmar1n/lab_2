#include <stdio.h>
#include <math.h>
#include "dev_exp_linear.h"

double dev_exp(double *radioactivity, double *time, int M, double decay_time)
{   
    double deviation1;
    double sum_residuals1 = 0;

    for ( int i = 0; i < M; i++ )
    {
        sum_residuals1 += pow((radioactivity[i] - exp(-1 * time[i] / decay_time)), 2) ;
    }
    deviation1 = sqrt(sum_residuals1) / M;
    return deviation1;
}

double dev_linear(double *radioactivity, double *time, int M, double decay_rate)
{
    double deviation2;
    double sum_residuals2 = 0;

    for ( int i = 0; i < M; i++ )
    {
        sum_residuals2 += pow((radioactivity[i] - (1 - time[i] / decay_rate)), 2);
    }
    deviation2 = sqrt(sum_residuals2) / M;
    return deviation2;
}