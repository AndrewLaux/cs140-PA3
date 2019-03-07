Last name of Student 1: Laux
First name of Student 1: Andrew
Email of Student 1: andrew_laux@ucsb.edu
Last name of Student 2:
First name of Student 2:
Email of Student 2:


----------------------------------------------------------------------------
Report for Question 1 
How is the code parallelized?



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




