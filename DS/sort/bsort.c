#include <stdio.h>

void sort(int arr[], int n);
int main(){
  int n;
  printf("Enter the array length: ");scanf("%d", &n);
  int i, arr[n];
  printf("Enter the array elements: ");
  for (i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  sort(arr, n);
  printf("The sorted array is: ");
  for (i = 0; i<n; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void sort(int arr[], int n){
  for (int i=0; i<n-1; i++) {
    int swapped = 0;
    for (int j=0; j<n-1-i;j++){
      if (arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        swapped = 1;
      }
    }
    if (swapped==0){
      break;
    }
  }
}
