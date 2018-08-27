/*
 * author: Summer Li
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "problem3.h"

// Implement a C function called level_2_opt. It should perform the same
// task as the implemented level_2 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.


void level_2(data * list, double * sum_d, int * sum_n)
{
    int i;

    for(i = 0; i < LARGER; i++){
        *sum_d += list[i].d;
    }

    for(i = 0; i < LARGER; i++){
        *sum_n += list[i].n1 ;
    }

    for(i = 0; i < LARGER; i++){
        *sum_n += list[i].n2;
    }

}

/* The original function: each loop visits the list data in memory order, reading one integer element each time. 
 * So the pattern for each loop is miss, hit, hit, miss, hit, hit and so on.
 * The optimized version reduced the repeat loop instruction from 3 to 1, access the data properties all at once,
 * and improve temporary locality.
 */


void level_2_opt(data * list, double * sum_d, int * sum_n)
{
    int i;

    for(i = 0; i < LARGER; i++){
        *sum_d += list[i].d;
        *sum_n += (list[i].n1 + list[i].n2);
    }

}
