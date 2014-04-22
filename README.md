fibonacci
=========

This program has four different functions that will calculate the nth digit of the fibonacci
sequence. The four versions are vanilla recursive, tail recursive, top-down dynamic, and
bottom-up dynamic (iterative).



//////////////////// How to use this program /////////////////////////

Use the function run_to_failure with the four different versions of
the fibonacci function and watch as the time to calculate increases,
of the program seg-faults due to the number of stack frames (I think).

Use the time function to time a specific input with a specific 
cersion of the fibonacci function.



//////////////////////////// Results ////////////////////////////

 Input needed to make function take over 5 seconds:
 
 vanilla recursive (fib1): 44
 tail recursive (fib2):    131072 (seg fault)
 top-down dynamic (fib3):  65536 (seg fault)
 bottom-up dynamic (fib4): 2147483648
