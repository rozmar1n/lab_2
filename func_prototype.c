#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 100

int experiment (double* radioactivity, double* time, double start_time, double end_time, double step);

int main (){
    double start_time = 0, end_time = 19.8, step = 0.2;
    double radioactivity[SIZE] = {};
    double time[SIZE] = {};
    int N = experiment (radioactivity, time, start_time, end_time, step);

    printf ("quantity is [%d]\n", N);
    for (int r = 0; r < SIZE; r++){
        printf ("[%d]  number is [%f] and time [%f]\n", r, radioactivity[r], time[r]);
    }
}

int experiment (double* radioactivity, double* time, double start_time, double end_time, double step){
    double const betta = 3;
    int n = 0;
    double helper = start_time;
    for (int i = 0; helper <= end_time; i++){
        time[i] = helper;
        n = i + 1;
        radioactivity[i] = exp(-time[i] / betta);
        helper = helper + step;
    } 
    return n;
}

