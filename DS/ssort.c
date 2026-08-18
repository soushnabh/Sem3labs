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
    int key = arr[i];
    int min = i;
    for (int j = i+1; j<n; j++){
      if (arr[j]<arr[min]){
        min = j;
      }
    }
    arr[i]=arr[min];
    arr[min]=key;
  }
}
