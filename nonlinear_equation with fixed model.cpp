#include <stdio.h>
#include <math.h>

#include "nonlinear_equation.h"

double nonlinear_equation(double *radioactivity, double *time, int N, double precision)
{
    double interval1 = 0, interval2 = 0, decay_time = 0, decay_time0 = -153.153153;
    int i = 0;
    scanf("%lg%lg", &interval1, &interval2);

    for(i; i < N; i++)
    {
        decay_time = (interval2 + interval1)/2;
        /*printf("interval1 = %lg\n", interval1);
        printf("interval2 = %lg\n", interval2);
        printf("\n");*/
        if ((model(radioactivity, decay_time) * model(radioactivity, interval1)) <= 0)
        {
            interval2 = decay_time;
            /*printf("interval2 = %lg\n", interval2);*/
        }
        else if ((model(radioactivity, decay_time) * model(radioactivity, interval2)) <= 0)
        {
            interval1 = decay_time;
            /*printf("interval1 = %lg\n", interval1);*/
        }

        if (fabs(interval2 - interval1) > 2 * precision)
        {
            continue;
        }
        else
        {
            decay_time0 = decay_time;
        }
    }

    if (IsEqual(decay_time0, -153.153153))
    {
        printf("\n<<<The root of nonlinear equation was not found!>>>\n");
        printf("%lg\n", decay_time0);
    }

    return 0;
}

int IsEqual(double elem1, double elem2, double precision)
{
    return (fabs(elem1 - elem2) <= precision);
}

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
