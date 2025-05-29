/* 
 * https://leetcode.com/problems/trapping-rain-water/
 * date : 16/05/25
 * Solution is too slow, needs to be optimized or changed (fails 4 out of 324 test cases on time limit exceeded)
*/
#include <stdio.h>
#include <stdlib.h>
int trap(int* height, int heightSize) {
    int max = 0;
    int numOfMax = 0;
    int j = 0;
    int *maxIndexArray = (int *) malloc(heightSize*sizeof(int));
    for (int i = 0; i<heightSize; i++){
        if (height[i] > max) {
            max = height[i];
            numOfMax = 1;
            maxIndexArray[0] = i;
            j = 0;
            continue;
        }
        if (height[i] == max) {
            maxIndexArray[++j] = i;
            numOfMax++;
        }
    }
    // remove stray max value if it exists.
    if (numOfMax == 1) {
        height[maxIndexArray[0]]--;
        max --;
    }

    int sum = 0;
    int tempSum = 0;
    int start = 0;

    while (max >= 0) {
        printf("max : %d\n", max);
        for (int i = 0; i<heightSize; i++) {
            printf("%d ", height[i]);
        }
        printf("\n");

        tempSum = 0;
        start = 0;

        for (int i = 0; i<heightSize; i++) {
            if (height[i] == max) {
                if (start == 1) {
                    sum += tempSum;
                    tempSum = 0;    
                } else {
                    start = 1;
                }
                    continue;
            }
            if (start = 1) {
                printf("increment count at : %d\n", height[i]);
                tempSum++;
            }
        }

        for (int i = 0; i<heightSize; i++){
            if (height[i] == max) {
                height[i]--;
            }
        }
        printf("%d\n", sum);
        max--;
    }

    return sum;
}

int main() {
  int *height = malloc(6*sizeof(int));
  height[0] = 4;
  height[1] = 2;
  height[2] = 0;
  height[3] = 3;
  height[4] = 2;
  height[5] = 5;
  int heightSize = 6;
  int x = trap(height, heightSize);
  printf("%d\n", x);
}
