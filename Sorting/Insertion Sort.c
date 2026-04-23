#include <stdio.h>
int main(void){
    int n, i, j, key, arr[20];
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("Array after insertion sort:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}