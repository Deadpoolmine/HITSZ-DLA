//*****************************************************************************
//
//Device: All
//Design Name: matrixmul
//Purpose:
//    This is a C++ version of a matrix multiplier example.
//Reference:
//Revision History:
//*****************************************************************************

#include "matrixmul.h"

typedef int data_t;
#define DIM_1 3
#define DIM_2 4
#define DIM_3 5

void matrixmul( mat_a_t A[DIM_1][DIM_2], mat_b_t B[DIM_2][DIM_3], result_t out[DIM_1][DIM_3])
{

    Row: for (int i = 0; i < DIM_1;  ++i)
    {
        Col: for(int j = 0; j < DIM_3; ++j)
        {
            data_t tmp = 0;
            Product: for(int t = 0; t < DIM_2; ++t)
            {
                tmp += A[i][t] * B[t][j];
            }
            out[i][j] = tmp;
        }
    }
}
