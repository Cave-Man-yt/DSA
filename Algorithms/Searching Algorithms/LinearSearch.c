// Linear Search Algorithm
#include <stdio.h>
#include <time.h>

#define N 1000000

int main() {
  int arr[N];
  int key, found = 0;

  for (int i = 0; i < N; i++) {
    arr[i] = i + 1;
  }

  key = N;

  clock_t begin = clock();
  for (int i = 0; i < N; i++) {
    if (arr[i] == key) {
      found = i;
      break;
    }
  }
  clock_t end = clock();

  if (found) {
    printf("Element found at index %d\n", found);
  } else {
    printf("Element not found\n");
  }

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time Spent: %f ms\n", time_spent * 1000);
  return 0;
}
