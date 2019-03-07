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

if(mappingtype == BLOCK_MAPPING) {
    mappingtype = BLOCK_CYCLIC;
    chunksize = matrix_dim / threadcnt;
  }

This checks to see if a Block cyclic cycle is passed in. If this is the case then the chunk size needs to be modified
to the number of iterations divided by the number of threads.


----------------------------------------------------------------------------
Parallel time/speedup/efficiency using 2 and 4 cores under different scheduling methods


|-------+------+------+---------+------------------+-----------+-----------+------------|
| Cores |    n |    t | mapping | cyclic-blocksize |  run-time |   speedup | efficiency |
|-------+------+------+---------+------------------+-----------+-----------+------------|
|     1 | 4096 | 1024 | block   | n/a              | 27.313195 |       n/a |        n/a |
|     2 | 4096 | 1024 | block   | n/a              | 20.339510 | 1.3428639 | 0.67056075 |
|     4 | 4096 | 1024 | block   | n/a              | 11.849637 | 2.3049816 | 0.57624540 |
|-------+------+------+---------+------------------+-----------+-----------+------------|


|-------+------+------+--------------+------------------+-----------+-----------+------------|
| Cores |    n |    t | mapping      | cyclic-blocksize |  run-time |   speedup | efficiency |
|-------+------+------+--------------+------------------+-----------+-----------+------------|
|     1 | 4096 | 1024 | block-cyclic |                1 | 27.309582 |       n/a |        n/a |
|     2 | 4096 | 1024 | block-cyclic |                1 | 14.208099 | 1.9221137 |  0.9610569 |
|     4 | 4096 | 1024 | block-cyclic |                1 |  7.399786 | 3.6905907 |  0.9226477 |
|-------+------+------+--------------+------------------+-----------+-----------+------------|


|-------+------+------+--------------+------------------+-----------+-----------+------------|
| Cores |    n |    t | mapping      | cyclic-blocksize |  run-time |   speedup | efficiency |
|-------+------+------+--------------+------------------+-----------+-----------+------------|
|     1 | 4096 | 1024 | block-cyclic |               16 | 27.314724 |       n/a |        n/a |
|     2 | 4096 | 1024 | block-cyclic |               16 | 13.686344 |  1.995765 |   0.997882 |
|     4 | 4096 | 1024 | block-cyclic |               16 |  7.015504 |   3.89348 |   0.97337  |
|-------+------+------+--------------+------------------+-----------+-----------+------------|


|-------+------+------+---------+-----------+-----------+-----------+------------|
| Cores |    n |    t | mapping | chunksize |  run-time |   speedup | efficiency |
|-------+------+------+---------+-----------+-----------+-----------+------------|
|     1 | 4096 | 1024 | dynamic |        16 | 27.322406 |       n/a |        n/a |
|     2 | 4096 | 1024 | dynamic |        16 | 13.779651 |  1.982808 |   0.991404 |
|     4 | 4096 | 1024 | dynamic |        16 |  6.972659 |  3.918506 |   0.979627 |
|-------+------+------+---------+-----------+-----------+-----------+------------|



If there are significant performance differences among different thread scheduling  methods,
provide a short reason. 

Given the upper-triangular matrix, the efficiency of the pure block mapping method suffers from load 
imbalancing (more zeros in the lower rows). The speedup of this method suffers as well compared to the others.


