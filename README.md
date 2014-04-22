fibonacci
=========

This program has four different functions that will calculate the nth digit of <br>
the fibonacci sequence. The four versions are vanilla recursive, tail recursive,<br>
top-down dynamic, and bottom-up dynamic (iterative).<br>

<br>

//////////////////// How to use this program /////////////////////////

Use the function run_to_failure with the four different versions of<br>
the fibonacci function and watch as the time to calculate increases,<br>
of the program seg-faults due to the number of stack frames (I think).<br>
<br>
Use the time function to time a specific input with a specific <br>
cersion of the fibonacci function.<br>

<br>

//////////////////////////// Results ////////////////////////////

 Input needed to make function take over 5 seconds:
 <br><br>
 vanilla recursive (fib1): 44 <br>
 tail recursive (fib2):    131072 (seg fault)<br>
 top-down dynamic (fib3):  65536 (seg fault)<br>
 bottom-up dynamic (fib4): 2147483648<br>
