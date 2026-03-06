#include <stdio.h>
#define MAX_SIZE 10

int top = -1;
int arr[MAX_SIZE];

void push(int n) {
  if (top <= MAX_SIZE) {
    arr[++top] = n;
  } else {
    printf("Stack overflow");
  }
}

int pop() {
  if (top != -1) {
    return arr[top--];
  }
  return -1;
}

void display() {
  for (int i = 0; i <= top; i++) {
    printf("%d", arr[i]);
  }
}

int main() {
  while (1) {
    int choice;
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    scanf("%d", &choice);
    int n, m;
    switch (choice) {
    case 1:
      printf("Enter Number to push: ");
      scanf("%d ", &n);
      push(n);
      break;
    case 2:
      m = pop();
      if (m != 1) {
        printf("Element %d is popped.\n", m);
      } else {
        printf("Stack Empty\n");
      }
      break;
    case 3:
      display();
      break;
    case 4:
      return 0;
    default:
      printf("Wrong input.");
    }
  }
}
