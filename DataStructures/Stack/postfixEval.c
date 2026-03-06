#include <ctype.h>
#include <stdio.h>
#include <string.h>

int top = -1;
int stack[100];

void push(int n) { stack[++top] = n; }
int pop() { return stack[top--]; }

int evaluatePostfix(char exp[]) {
  for (int i = 0; i < strlen(exp); i++) {
    char c = exp[i];
    if (isdigit(c)) {
      push(c - '0');
    } else {
      int val1 = pop();
      int val2 = pop();
      switch (c) {
      case '+':
        push(val1 + val2);
        break;
      case '-':
        push(val1 - val2);
        break;
      case '*':
        push(val1 * val2);
        break;
      case '/':
        push(val1 / val2);
        break;
      }
    }
  }
  return pop();
}

int main() {
  char exp[100];
  printf("Enter a postfix expression: ");
  scanf("%s", exp);
  int result = evaluatePostfix(exp);
  printf("\nValue: %d", result);
}
