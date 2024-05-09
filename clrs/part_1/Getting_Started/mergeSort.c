#include<stdio.h>
#include<stdlib.h>


int mergeSort(int * array, int Start, int Mid, int End){
  
  //for(int i = Start; i<End; i++){printf("%d ", array[i]);}printf("\n");
  
  
  // Initiate the left and right arrays
  int LeftArraySize = Mid-Start+1;
  int RightArraySize = End-Mid;
  
  int *LeftArray = malloc(sizeof(int)*LeftArraySize);
  int *RightArray = malloc(sizeof(int)*RightArraySize);
  
  //printf("LAS:%d RAS:%d\n", LeftArraySize, RightArraySize);

  // Copy the values from the main array to Each of the left and right arrays
  for(int i=0; i<LeftArraySize; i++){
    LeftArray[i] = array[Start + i];
  }
  for(int j=0; j<RightArraySize; j++){
    RightArray[j] = array[Mid +j + 1];
  }
  
  //for(int i = 0;i < LeftArraySize; i++){printf("%d ", LeftArray[i]);}printf("\n");
  //for(int i = 0;i < RightArraySize; i++){printf("%d ", RightArray[i]);}printf("\n");

  
  int i = 0;    // iterator i to iterate through left array
  int j = 0;    // iterator j to iterate through right array
  int k = Start;// iterator k to iterate through the main array

  // Main merge sort logic
  while(i<LeftArraySize && j<RightArraySize){
    if(LeftArray[i]<=RightArray[j]){
      array[k] = LeftArray[i];
      i++;
    }
    else{
      array[k] = RightArray[j];
      j++;
    }
    k++;
  }
  // Add the remaining values of either left or right array to main array
  while(i<LeftArraySize){
    array[k] = LeftArray[i];
    i++; k++;
  }
  while(j<RightArraySize){
    array[k] = RightArray[j];
    j++;k++;
  }
  free(LeftArray); free(RightArray);
  
  return 0;
}

void mergeRecur(int * array, int Start, int End){
  
  if(Start >= End){
    return;
  }
  int Mid = (Start + End)/2;

  //for (int i = Start; i<=End; i++){printf("%d ", array[i]);}printf("------%d %d %d\n", Start, Mid, End);
  mergeRecur(array, Start, Mid);
  mergeRecur(array, Mid+1, End);
  mergeSort(array,Start, Mid, End);
}


int main(){
  
  int LenOfArray;

  printf("Enter Length of Array:");
  scanf("%d", &LenOfArray);getchar();
  
  int * array = malloc(sizeof(int)*(LenOfArray+1));
  
  char c;
  
  printf("Enter Numbers: ");
  for(int i = 0; i<LenOfArray;i++){
    scanf("%d", &array[i]);
  }

  mergeRecur(array, 0, LenOfArray-1);
  
  for (int i = 0; i<LenOfArray; i++){printf("%d ", array[i]);}printf("\n");
  free(array);
}
