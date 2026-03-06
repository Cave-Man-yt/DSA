#include <stdio.h>
#define MAX_SIZE 10

int top = -1, rear = -1;
int arr[MAX_SIZE];

void enqueue() {
  printf("Enter element to queue: ");
  int n;
  scanf("%d", &n);
  if (rear == MAX_SIZE - 1) {
    printf("Queue Overflow\n");
    return;
  }
  if (top == -1) {
    top++;
  }
  arr[++rear] = n;
}

void dequeue() {
  if (top == -1 || top > rear) {
    printf("Queue Underflow");
    return;
  }
  top++;
  printf("Element %d is deleted", arr[top - 1]);
}

void display() {
  for (int i = top; i <= rear; i++) {
    printf("\n%d ", arr[i]);
  }
}

int main() {
  int choice;
  while (1) {
    printf("QUEUE MENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter "
           "choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      return 0;
    }
  }
  return 0;
}
