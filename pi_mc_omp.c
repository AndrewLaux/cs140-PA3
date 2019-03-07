/*
 * File:     pi_mc_openmp.c
 *
 * Purpose:  Thread function that Estimates pi using a monte carlo method
 */

#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

/* Global variables */
long long int number_in_circle = 0;
long long int number_of_tosses;

/*---------------------------------------------------------------------
 * Function:  parallel_loop
 * Purpose:  Calculate number in circle using monte carlo method
 *    threadcnt: number of threads to run
 * Global in vars: number_of_tosses
 * Global out vars: number_in_circle
 */

void parallel_loop(int threadcnt) {
  /*Your solution with OpenMP*/

  long long int toss;
  long long int sum = 0;
  double x, y, distance_squared;
  srandom(0);

 
#pragma omp parallel num_threads(threadcnt) private(toss, x, y, distance_squared) reduction(+: sum)
 {
  #pragma omp for
  for (toss = 0; toss < number_of_tosses; toss++) {
    x = 2 * random() / ((double)RAND_MAX) - 1.0;
    y = 2 * random() / ((double)RAND_MAX) - 1.0;
    distance_squared = x * x + y * y;
    if (distance_squared <= 1) {
      sum++;
    }
  }
 }
  number_in_circle += sum;
}

/*---------------------------------------------------------------------
 * Function:  parallel_pi
 * Purpose:  Calculate number in circle using monte carlo method
 * In arg:  no_tosses: number of tosses
 *    threadcnt: number of threads to run
 * Global out vars: number_in_circle
 */
double parallel_pi(long long int no_tosses, int threadcnt) {
  double pi_estimate;

  number_of_tosses = no_tosses;
  number_in_circle = 0;

  parallel_loop(threadcnt);
  pi_estimate = 4.0 * number_in_circle / ((double)number_of_tosses);
  return pi_estimate;
}
