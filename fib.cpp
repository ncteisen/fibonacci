// Noah Eisen

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <climits>
#include <vector>
#include <ctime>

#define long unsigned long long

using namespace std;

void test_fibs();
long fib1(long n);
long fib2(long n);
long fib3(long n);
long fib4(long n);
long fib5(long n);
void run_to_failure(long (*fib)(long));
void time(long (*fib)(long), long n);

int main()
{
    cout << std::setprecision(3);
    cout << std::fixed;
    
    //test_fibs();
    
    //run_to_failure(fib1);
    //run_to_failure(fib2);
    //run_to_failure(fib3);
    //run_to_failure(fib4);
}

////////////////////////////////////////////////////////////////////////////

/*
 Input needed to make function take over 5 seconds:
 
 vanilla recursive (fib1): 44
 tail recursive (fib2):    131072 (seg fault)
 top-down dynamic (fib3):  65536 (seg fault)
 bottom-up dynamic (fib4): 2147483648
 
 */

////////////////////////////////////////////////////////////////////////////

/* simple vanila recursive fib function */
// n is the length of the fibonacci
long fib1(long n) {
    if (n <= 1) return 1;// base case
    return fib1(n - 1) + fib1(n - 2);// recurcive call if the condition is not met yet
}

////////////////////////////////////////////////////////////////////////////

/* tail recursive fib function (could be considered bottom-up dynamic) */

// neccesary helper function
static long fib2_help(long n, long val, long old) {
    if (n == 0) return old;                     // trivial base case
    if (n == 1) return val;                     // base case
    return fib2_help(n - 1, val + old, val);    // recursive call (note tail-ness)
}

long fib2(long n) {
    return fib2_help(n, 1, 1);
}

////////////////////////////////////////////////////////////////////////////

/* top-down dynamic algorithm */

long fib3(long n) {
    if (n <= 1) return 1;                           // base case
    static vector<long> computed(n + 1, 0);         // this vector holds computed vals
    if (computed[n]) return computed[n];            // if we have already computed it
    return computed[n] = fib3(n - 1) + fib3(n - 2); // if we have not computed it yet
}

////////////////////////////////////////////////////////////////////////////

/* bottom-up dynamic algorithm */

long fib4(long n) {
    long cur_fib = 1;
    long prev_fib = 1;
    for (int i = 0; i + 1 < n; ++i) {
        long temp = cur_fib;
        cur_fib = cur_fib + prev_fib;
        prev_fib = temp;
    }
    
    return cur_fib;
}

////////////////////////////////////////////////////////////////////////////

void test_fibs()
{
    assert(fib1(0) == 1);
    assert(fib1(1) == 1);
    assert(fib1(2) == 2);
    assert(fib1(3) == 3);
    assert(fib1(4) == 5);
    assert(fib1(5) == 8);
    assert(fib1(10) == 89);
    assert(fib1(20) == 10946);
    cout << "fib1 passes\n";
    
    assert(fib2(0) == 1);
    assert(fib2(1) == 1);
    assert(fib2(2) == 2);
    assert(fib2(3) == 3);
    assert(fib2(4) == 5);
    assert(fib2(5) == 8);
    assert(fib2(10) == 89);
    assert(fib2(20) == 10946);
    cout << "fib2 passes\n";
    
    assert(fib3(0) == 1);
    assert(fib3(1) == 1);
    assert(fib3(2) == 2);
    assert(fib3(3) == 3);
    assert(fib3(4) == 5);
    assert(fib3(5) == 8);
    assert(fib3(10) == 89);
    assert(fib3(20) == 10946);
    cout << "fib3 passes\n";
    
    assert(fib4(0) == 1);
    assert(fib4(1) == 1);
    assert(fib4(2) == 2);
    assert(fib4(3) == 3);
    assert(fib4(4) == 5);
    assert(fib4(5) == 8);
    assert(fib4(10) == 89);
    assert(fib4(20) == 10946);
    cout << "fib4 passes\n";
}

////////////////////////////////////////////////////////////////////////////

void run_to_failure(long (*fib)(long))
{
    for (long i = 1; i < ULLONG_MAX; i *= 2)
        time(fib, i);
}

void time(long (*fib)(long), long n)
{
    auto start = clock();
    fib(n);
    cout << "fib(" << n << ") took " << (clock() - start) / (double)CLOCKS_PER_SEC << " seconds\n";
}
