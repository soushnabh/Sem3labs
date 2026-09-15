#include <stdio.h>

void insert(int arr[], int n, int *front, int *rear);
void delete(int arr[], int n, int *front, int *rear);
int main() {
  int n;
  printf("Enter the number of elements: ");scanf("%d",&n);
  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }
  int front = 0;
  int rear = n-1;
  char op;
  int exit = 0;
  printf("Enter the operation ((i)nsert or (d)elete or (q)uit): ");
  while (exit==0) { 
    scanf("%c",&op);
    switch (op){
      case 'i': {
          insert(arr, n, &front, &rear);
          break;
        }
      case 'd': {
          delete(arr, n, &front, &rear);
          break;
        }
      case 'q': {
          exit = 1;
        }
      default : {
        continue;
      }
    }
    if (front == -1) {
      printf("The array is empty.\n");
    } else {
    for (int i=front; i<=rear; i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
    }
  }
}
void insert(int arr[], int n, int *front, int *rear){
  if (*rear == n-1) {
    printf("Overflow error.\n");
    return;
  } else {
    int val;
    printf("Enter the element to be inserted: ");scanf("%d",&val);
    if (*front == -1 && *rear == -1){
      *front = 0; *rear = 0;
    } else {
      *rear += 1;
    }
    arr[*rear]=val;
  }
}
void delete(int arr[], int n, int *front, int *rear){
  if (*front == -1) {
    printf("Underflow error.\n");
    return;
  } else {
    printf("The removed element is: %d\n", arr[*front]);
    *front+=1;
  }
}
