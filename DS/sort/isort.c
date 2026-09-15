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
  for (int i = 1; i<n; i++){
    int key = arr[i];
    int j = i-1;
    while (j>=0 && arr[j]>key) {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }  
}
