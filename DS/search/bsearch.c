#include <stdio.h>


int binary_search(int arr[],int n, int key);
int main(){
  int n;
  printf("Enter the sorted array length: ");scanf("%d", &n); 
  int a[n];
  int i;
  printf("Enter the sorted array elements: ");
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int key;
  printf("Enter the key: ");scanf("%d", &key); 
  int idx = binary_search(a, n, key);
  if (idx>=0){
    printf("The index is %d\n", idx);
    return 0;
  }
  else {
    printf("The index could not be found\n");
    return 1;
  }
}

// Must be a sorted array
int binary_search(int arr[],int n, int key) {
  int lo = 0;
  int hi = n;
  while (lo<=hi){
    int mid = (lo + hi)/2;
    if (arr[mid]==key){
      return mid;
    }
    else if (arr[mid]<key){
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
  }
  return -1;
}
