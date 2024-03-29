// Solution to Bad Signal
// Author: Thomas Beuman

// Time complexity: O(n)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: only check microphone with strongest received signal


#include <cstdio>
using namespace std;


double R[100000];


int main()
{ int cases, casenr, n, B, px, py, x, y, s, i, m;
  double sum;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input and calculate received signal strengths
    scanf("%d\n%d\n%d %d\n", &n, &B, &px, &py);
    for (i = 0; i < n; i++)
    { scanf("%d %d %d\n", &x, &y, &s);
      R[i] = s / ((double)(x-px)*(x-px) + (double)(y-py)*(y-py));
    }

    // Find microphone with strongest received signal
    m = 0;
    for (i = 1; i < n; i++)
      if (R[i] > R[m])
        m = i;

    // Calculate sum of the strengths of all other microphones
    sum = 0;
    for (i = 0; i < n; i++)
      if (i != m)
        sum += R[i];

    // Check and print result
    if (R[m] > 6 * (B + sum))
      printf("%d\n", m+1);
    else
      printf("NOISE\n");
  }
  return 0;
}

