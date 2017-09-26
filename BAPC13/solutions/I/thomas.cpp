// Solution to Identification Codes
// Author: Thomas Beuman

// Time complexity: O(sqrt(c))
// Memory: O(log(c))

// @EXPECTED_RESULTS@: CORRECT

// Solution method:
//   Find all prime factors of c and determine multiplicity
//   Decompose prime powers p^n into factors of the form p^(2^k)


#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


int SIC[99];


int main()
{ 
  int cases, casenr, c, n, p, m, s, i;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    scanf("%d\n", &c);
    n = 0; // Number of SICs

    // Loop over all possible divisors <= sqrt(c)
    for (p = 2; p*p <= c; p++)
    { 
      // Determine largest prime power m of p that divides c
      // and divide out all factors of p
      for (m = 1; c % p == 0; c /= p, m *= p);

      // Find largest prime power s = p^(2^k) not larger than m
      for (s = p; s <= m/s; s *= s);

      // Add all s that fit in (the remainder of) m
      for (; s >= p; s = sqrt(s))
        if (s <= m)
        { SIC[n++] = s;
          m /= s;
        }
    }

    // Check if there is still something left (this is then prime)
    if (c > 1)
      SIC[n++] = c;

    // Sort the SICs and print
    sort(SIC, SIC+n);
    for (i = 0; i < n; i++)
      printf("%d%c", SIC[i], i < n-1 ? ' ' : '\n');
  }
  return 0;
}

