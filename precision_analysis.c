#include "precision_analysis.h"

double precision_analysis (double *radioactivity, double *time, int N)
       {
           for (int numberElements = 10; numberElements <= N; numberElements++)
           {
                double decay_time = nonlinear_equation (radioactivity, time, numberElements);
                double decay_rate = linear_equation (radioactivity, time, numberElements);

                if (2 * dev_exp (radioactivity, time, numberElements, decay_time) <=
                   dev_linear(radioactivity, time, numberElements, decay_rate))
                   return time[numberElements];
           }

           return 123321;
       }