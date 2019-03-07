Last name of Student 1: Laux
First name of Student 1: Andrew
Email of Student 1: andrew_laux@ucsb.edu
Last name of Student 2:
First name of Student 2:
Email of Student 2:


----------------------------------------------------------------------------
Report for Question 1 
How is the code parallelized?

Q1 - pi

#pragma omp parallel num_threads(threadcnt) private(toss, x, y, distance_squared) reduction(+: sum)
This indicates that we wish to run the following code section in parallel.
num_threads clause specifies the number of threads we want, in this case the arg threadcnt.
The private clause localizes the list of variables to each thread. We don't want threads intefering with eachother.
Finally the reduction the clause tells each thread to add its sum to the main thread sum which assigns it to
number_in_circle.

#pragma omp for
The previous line indicates that we wish to run the code section in parallel but that is not precisely what we need.
Instead of having each thread process the entire toss loop we want each thread to handle a different section of the
loop so that the team of threads can compute it more efficiently. For this we use the omp for declaration.


----------------------------------------------------------------------------
Report for Question 2 
How is the code parallelized?


----------------------------------------------------------------------------
Parallel time/speedup/efficiency using 2 and 4 cores under different scheduling methods


1 Thread

Test 12: n=4K t=1K upper block mapping: Wall clock time = 27.316558 with 1 threads
Test 13: n=4K t=1K upper block cylic (r=1): Wall clock time = 27.309582 with 1 threads
Test 14: n=4K t=1K upper block cyclic(r=16): Wall clock time = 27.314724 with 1 threads
Test 14a: n=4K t=1K upper dynamic(r=16): Wall clock time = 27.322406 with 1 threads

2 Threads

Test 12: n=4K t=1K upper block mapping: Wall clock time = 20.339510 with 2 threads
Test 13: n=4K t=1K upper block cylic (r=1): Wall clock time = 14.208099 with 2 threads
Test 14: n=4K t=1K upper block cyclic(r=16): Wall clock time = 13.686344 with 2 threads
Test 14a: n=4K t=1K upper dynamic(r=16): Wall clock time = 13.779651 with 2 threads

4 Threads 

Test 12: n=4K t=1K upper block mapping: Wall clock time = 11.849637 with 4 threads
Test 13: n=4K t=1K upper block cylic (r=1): Wall clock time = 7.399786 with 4 threads
Test 14: n=4K t=1K upper block cyclic(r=16): Wall clock time = 7.015504 with 4 threads
Test 14a: n=4K t=1K upper dynamic(r=16): Wall clock time = 6.972659 with 4 threads


If there are significant performance differences among different thread scheduling  methods,
provide a short reason. 




