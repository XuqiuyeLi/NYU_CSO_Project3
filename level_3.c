/*
 * author: Summer Li
 * 
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "problem3.h"

// Implement a C function called level_3_opt. It should perform the same
// task as the implemented level_3 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.
// Note that this function does not return any value. It modifies the array
// that is passed to it, instead.

void level_3 (int *A, int n)
{
    int  i, j;
    for (i = 0; i < n; i++)
    	for (j = 0; j < n; j++)
        	A[j*n + i] = A[j*n + i] || A[i*n + j];

}

/*
 * Changing the order of the two loops, ensures that
 * the array elements are accessed using stride-1, instead of
 * strige-N patern in the original function.
 * 
 */

void level_3_opt (int *A, int n)
{
	int  i, j, k;
	for (j = 0; j < n; j++)
	     k = j*n;
    	     for (i = 0; i < n; i++)
        	A[k + i] = A[k + i] || A[i*n + j];

}
