#include <stdio.h>
#include <stdlib.h>

int main() {
   char* charArr = (char*)malloc(8);
   for(int i=0; i<8; i++) {
       charArr[i] = 'a';  
   }
}