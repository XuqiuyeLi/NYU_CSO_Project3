/*
 * author: Summer Li
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "problem3.h"

// Implement a C function called level_1_opt. It should perform the same
// task as the implemented level_1 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.
//
// Note: your function needs to compute the entire matrix C,
// not only its x entry.

long level_1(long * B, long * A, int x)
{
    long * C = (long * ) malloc (N*N*sizeof(long) );
    if (!C) return 0;

    int c, r;

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r*N + c ] = B[ r*N + c ] + A[ c*N + r ] ;

    long ret = C[x];
    free (C); C = 0;
    return ret;
}


/*
 * Changing the order of the two loops, ensures that
 * the array elements are accessed using stride-1, instead of
 * strige-N patern in the original function.
 * Both C and B are exploiting good locality.
 */


long level_1_opt(long * B, long * A, int x)
{
    // DO NOT modify the following declarations
    long * C = (long * ) malloc (N*N*sizeof(long) );
    if (!C) return 0;

    // enter your code here
    int r, c, m;
    for(r = 0; r < N; r++)
        m = r*N;
        for(c = 0; c < N; c++)
             C[ m + c ] = B[ m + c ] + A[ c*N + r ] ;


    //DO NOT modify the rest of this function
    long ret = C[x];
    free (C); C = 0;
    return ret;
}
