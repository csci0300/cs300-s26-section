#include <stdio.h>
#include <stdlib.h>

int main() {
   int* alloc = malloc(sizeof(int) * 2);
   int* array = malloc(sizeof(int) * 4);
   array = alloc;

   int *track;
   for (int i = 0; i<2; i++) {
       printf("Index %i = %i\n", i, array[i + 1]);
       track = &array[i];
   }

   free(alloc);
   printf("%i\n", *track);
   free(array);
}
