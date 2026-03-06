#include <ctype.h>
#include <stdio.h>
#include <string.h>

int top = -1;
char stack[100];

void push(char c) { stack[++top] = c; }

char peek() { return stack[top]; }

char pop() { return stack[top--]; }

int precedence(char c) {
  if (c == '^')
    return 3;
  if (c == '*' || c == '/')
    return 2;
  if (c == '+' || c == '-')
    return 1;
  return 0;
}

int isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char exp[], char out[]) {
  int k = 0;
  for (int i = 0; i < strlen(exp); i++) {
    char c = exp[i];
    if (isalnum(c)) {
      out[k++] = c;
    } else if (c == '(') {
      push(c);
    } else if (c == ')') {
      while (top != 1 && peek() != '(') {
        out[k++] = pop();
      }
      pop();
    } else if (isOperator(c)) {
      while (top != -1 && precedence(peek()) >= precedence(c)) {
        out[k++] = pop();
      }
      push(c);
    }
  }
  while (top != -1) {
    out[k++] = pop();
  }
  out[k] = '\0';
}

int main() {
  char exp[100], out[100];
  printf("Enter an infix expression: ");
  scanf("%s", exp);
  infixToPostfix(exp, out);
  printf("Postfix expression: %s", out);
}
