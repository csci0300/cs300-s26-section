#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *num = (int *)malloc(sizeof(int));
   int *array1 = (int *)malloc(2 * sizeof(int));
   long *array2 = (long *)array1;

   *num = 42;
   free(num);

   array1[0] = 999;
   array1[1] = 888;
   array2[0] = 300;
   array2[1] = 600;

   *(array1 - 8) = 100;
}