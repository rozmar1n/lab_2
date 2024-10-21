#include "main.h"

int main(void)
{
    printf("something\n");
    double start_time = 0, end_time = 9.9, step = 0.1/*, precision = 0.001*/;
    double radioactivity[SIZE] = {0};
    double time[SIZE] = {0};
// fprintf(stderr, "all is good\n");
    int N = experiment(radioactivity, time, start_time, end_time, step);
// fprintf(stderr, "int N: %d\n", N);
// fprintf(stderr, "radioactivity before noise:\n");
// for (int i = 0; i < N; i++)
// {
//     fprintf(stderr, "%lg ", radioactivity[i]);
// }
// fprintf(stderr, "\n");
    
    
    add_noise (radioactivity, N);
// fprintf(stderr, "after add noise:\n");
// for (int i = 0; i < N; i++)
// {
//     fprintf(stderr, "%lg ", radioactivity[i]);
// }
// fprintf(stderr, "\n");
    
    double decay_time = nonlinear_equation (radioactivity, time, N);
fprintf(stderr, "decay time: %lg\n", decay_time);
    
    double decay_rate = linear_equation (radioactivity, time, N);
fprintf(stderr, "decay_rate: %lg\n", decay_rate);
    
    double time_differences = precision_analysis (radioactivity, time, N);
fprintf(stderr, "time_difference: %lg", time_differences);
    
    //fprintf(stderr, "decay_time: %lf\t\t\ndecay_rate: %lf\t\t\ntime difference: %lf\t\t\n", decay_time, decay_rate, time_differences);
    return 0;
}