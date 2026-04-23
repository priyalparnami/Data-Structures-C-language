#include <stdio.h>
int partition(int arr[], int p, int r){
    int x = arr[r];   // pivot
    int i = p - 1;
    for(int j = p; j <= r - 1; j++){
        if(arr[j] <= x) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

void quickSort(int arr[], int p, int r){
    if(p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main(void){
    int n, arr[50];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}