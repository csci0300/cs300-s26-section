#include <stdio.h>
#include <stdlib.h>

void update_and_free(int* obj) {
   *obj = 5;
   free(obj);
}

int main() {
   int* obj = (int*)malloc(sizeof(int));
   update_and_free(obj);
   *obj = 10;
}