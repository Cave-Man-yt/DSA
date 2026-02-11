// Binary search algorithm
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
  int low = 0, high = N - 1;
  int mid = (low + high) / 2;
  while (found == 0 && low <= high) {
    mid = (low + high) / 2;
    if (key > arr[mid]) {
      low = mid + 1;
    } else if (key < arr[mid]) {
      high = mid - 1;
    } else {
      found = mid;
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
