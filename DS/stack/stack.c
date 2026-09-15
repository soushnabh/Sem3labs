#include <stdio.h>

void push(int arr[], int n, int *top);
void pop(int arr[], int n, int *top);
int main() {
  int n;
  printf("Enter the number of elements: ");scanf("%d",&n);
  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }
  int top = n-1;
  char op;
  int exit = 0;
  printf("Enter the operation (p(u)sh or p(o)p or (q)uit): ");
  while (exit==0) { 
    scanf("%c",&op);
    switch (op){
      case 'u': {
          push(arr, n, &top);
          break;
        }
      case 'o': {
          pop(arr, n, &top);
          break;
        }
      case 'q': {
          exit = 1;
        }
      default : {
        continue;
      }
    }
    for (int i=0; i<=top; i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
  }
}
void push(int arr[], int n, int *top){
  if (*top == n-1) {
    printf("Overflow error.\n");
    return;
  } else {
    int val;
    printf("Enter the element to be pushed: ");scanf("%d",&val);
    *top+=1;
    arr[*top]=val;
  }
}
void pop(int arr[], int n, int *top){
  if (*top == -1) {
    printf("Underflow error.\n");
    return;
  } else {
    printf("The popped element is: %d\n", arr[*top]);
    *top-=1;
  }
}
