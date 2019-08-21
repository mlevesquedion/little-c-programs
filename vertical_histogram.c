#include <stdio.h>
#include <stdlib.h>

#define N_DIGITS 10

int array_max(int* array, int size)
{
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  return max;
}

int int_width(int x)
{
  int width = 0;
  while (x > 0) {
    width++;
    x /= 10;
  }
  return width;
}

void print_padding(int padding)
{
  for (int i = 0; i < padding; i++)
    putchar(' ');
}

void print_slice(int height, int counts[N_DIGITS])
{
  printf("%d", height);
  for (int j = 0; j < N_DIGITS; j++) {
    if (counts[j] >= height)
      printf("█");
    else
      putchar(' ');
  }
  putchar('\n');
}

void print_slices(int max_height, int max_padding, int counts[N_DIGITS])
{
  for (int height = max_height; height > 0; height--) {
    int padding = int_width(height);
    print_padding(max_padding - padding);
    print_slice(height, counts);
  }
}

void print_labels(int padding)
{
  print_padding(padding);
  for (int i = 0; i < N_DIGITS; i++) {
    printf("%d", i);
  }
  putchar('\n');
}

void print_histogram(int counts[N_DIGITS])
{
  int max_height = array_max(counts, N_DIGITS);
  int max_padding = int_width(max_height);

  print_slices(max_height, max_padding, counts);

  print_labels(max_padding);
}

int* count_digits()
{
  int* digit_counts = (int*)malloc(sizeof(int) * N_DIGITS);
  int c;
  while ((c = getchar()) != EOF) {
    if ('0' <= c && c <= '9') {
      digit_counts[c - '0']++;
    }
  }
  return digit_counts;
}

int main(int argc, const char* argv[])
{
  int* digit_counts = count_digits();
  print_histogram(digit_counts);
  return 0;
}
