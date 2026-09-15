#include <stdio.h>


int linear_search(int arr[],int n, int key);
int main(){
  int n;
  printf("Enter the array length: ");scanf("%d", &n); 
  int a[n];
  int i;
  printf("Enter the array elements: ");
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int key;
  printf("Enter the key: ");scanf("%d", &key); 
  int idx = linear_search(a, n, key);
  if (idx>=0){
    printf("The index is %d\n", idx);
    return 0;
  }
  else {
    printf("The index could not be found\n");
    return 1;
  }
}

int linear_search(int arr[],int n, int key) {
  int i;
  for (i = 0; i<n; i++) {
    if (arr[i]==key) {return i;}
  }  
  return -1;
}
