#include <stdio.h>
int main(void){
    int n, i, j, minindex, temp, arr[20];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n - 1; i++){
        minindex = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        if(minindex != i){
            temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
        }
    }
    printf("Array after selection sort:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}