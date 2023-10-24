/**
 * @file my_parallel.cc
 * @author Johnny Gilbert (jg480318)
 * @brief Computes a summation of powers modular 1000000
 * @date 2022-02-07
 */

#include <iostream>
#include <iomanip>
#include <omp.h>

using namespace std;

/**
 * @brief recursive function that computes powers of itself through
 * repeated multiplication modular 1000000
 * 
 * @param p the result of a term a^a%1000000
 * @param a the term we are trying to find raised to itself
 * @param n the exponent associated with a
 * @return long int 
 */
long int power(unsigned long int p, long int a, long int n) {
  // base case to end recursion
  if (n < 1) {
    return p;
  }
  // if n is odd multiply by a and subtract one to make n event
  if (n%2 == 1){
    p = (p * a)%1000000;
    n -= 1;
  }
  // when n is even double the power of a
  p = power(p, (a * a)%1000000, n/2);
  return p;
}

int main() {
  int n;
  unsigned long int sum = 0;
  long int partialSum;
  cin >> n;
#pragma omp parallel for reduction(+: sum) schedule(guided, 100000)
  for (int i=1;i<=n;i++) {
    partialSum = power(1, i, i);
    sum += partialSum;
  }
  cout << setw(6) << setfill('0') << sum%1000000 << endl;
}
