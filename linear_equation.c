#include <stdio.h>

#include "linear_equation.h"

double linear_equation (double *radioactivity, double *time, int N)
    {
    double decay_rate = 0, numerator = 0, denominator = 0;

    for ( int i = 0; i < N; i++)
        {
        numerator   += time[i] * time[i];
        denominator += time[i] * ( 1 - radioactivity[i] );
        }

    if ( numerator == 0 || denominator == 0 )
        {
        printf (
        "\033[1;31m" "\n----------WARNING!----------\n"   "\033[0m" 
        "linear_equation: in decay_rate numerator or denominator == 0\n"
            "numerator = " "\033[1;33m" "%f" "\033[0m"
        ", denominator = " "\033[1;33m" "%f" "\033[0m"
        "\033[1;31m" "\n----------------------------\n\n" "\033[0m", 
        numerator, denominator );
        }

    decay_rate = numerator / denominator;

    if ( decay_rate == 0 )
        {
        printf (
        "\033[1;31m" "\n----------WARNING!----------\n"   "\033[0m" 
        "linear_equation: decay_rate\n"
            "numerator = " "\033[1;33m" "%f" "\033[0m"
        ", denominator = " "\033[1;33m" "%f" "\033[0m"
        ", decate_rate = " "\033[1;33m" "%f" "\033[0m"
        "\033[1;31m" "\n----------------------------\n\n" "\033[0m", 
        numerator, denominator, decay_rate );
        }

    return decay_rate;    
    }