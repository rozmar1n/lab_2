#include <stdio.h>
#include <math.h>

double dev_exp(double *radioactivity, double *time, int M, double decay_time)
{   
    double deviation1;
    double sum_residuals1 = 0;

    for ( int i = 0; i < M; i++ )
    {
        sum_residuals1 = sum_residuals1 + (radioactivity[i] - exp(-1 * time[i] / decay_time));
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
        sum_residuals2 = sum_residuals2 + (radioactivity[i] - (1 - time[i] / decay_rate));
    }
    deviation2 = sqrt(sum_residuals2) / M;
    return deviation2; 
}