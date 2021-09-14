#include <iostream>
int sub(int n, int *A, int *B, int *C)
{
    int maximum = A[0];
    for(int i = 0; i < n; i++)
    {
        if(maximum<A[i])
            maximum = A[i];
        if(maximum<B[i])
            maximum = B[i];
        if(maximum<C[i])
            maximum = C[i];
    }
    return maximum;
}