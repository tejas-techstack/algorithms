#include<stdio.h>
#define ARRAY_MAX 5
int main(){
  int array[ARRAY_MAX] = {5,4,3,2,1};
  int key = 0;
  int j = 0;

  for (int i = 1; i < ARRAY_MAX; i++){
    key = array[i];
    j = i - 1;

    while (j>=0 && array[j]>key){
      array[j+1] = array[j];
      j = j-1;
    }
    array[j+1] = key;
  }
  
  for (int k = 0; k<ARRAY_MAX; k++){
    printf("%d ", array[k]);
  }
  printf("\n");
}
