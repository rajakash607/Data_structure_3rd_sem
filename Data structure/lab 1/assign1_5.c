#include<stdio.h>

int main() {
    int arr[6] = {23, 56, 12, 88, 18, 414};
    int min = arr[0], secondMin = arr[0], max = arr[0];

    for (int i = 0; i < 6; i++) {
        if (arr[i] < min) {
            secondMin = min;
            min = arr[i];
        } else if (arr[i] < secondMin && arr[i] != min) {
            secondMin = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Minimum: %d\n", min);
    printf("Second Minimum: %d\n", secondMin);
    printf("Maximum: %d\n", max);

    for(int i = 0; i < 6; i++) {
        if(arr[i]!=min && arr[i]!=max && arr[i]!=secondMin) {
            printf("%d ",arr[i]);
        }
        
    }


    return 0;
}
