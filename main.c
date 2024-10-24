#include "main.h"

int main(void)
{
    printf("something\n");
    double start_time = 0, end_time = 9.9, step = 0.1/*, precision = 0.001*/;
    double radioactivity[SIZE] = {0};
    double time[SIZE] = {0};
    int N = experiment(radioactivity, time, start_time, end_time, step);
    
    
    add_noise (radioactivity, N);
    
    double decay_time = nonlinear_equation (radioactivity, time, N);
    
    double decay_rate = linear_equation (radioactivity, time, N);
    
    double time_differences = precision_analysis (radioactivity, time, N);
    
    fprintf(stderr, "decay_time: %lf\t\t\ndecay_rate: %lf\t\t\ntime difference: %lf\t\t\n", decay_time, decay_rate, time_differences);
    return 0;
}