#include "main.h"

int main(void)
{
    printf("something\n");
    double start_time = 0, end_time = 9.9, step = 0.1;
    double radioctivity[SIZE] = {0};
    double time[SIZE] ={0};
    int N = experiement(radioctivity, time, start_time, end_time, step);
}