// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  return counter;
}

int countPairs2(int *arr, int len, int value) {
  int left = 0;
  int right = len - 1;
  int counter = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        counter += n * (n - 1) / 2;
        break;
      } else {
        int left_count = 1;
        int right_count = 1;
        int leftHelp = left + 1;
        while (leftHelp < right && arr[leftHelp] == arr[left]) {
          left_count++;
          leftHelp++;
        }
        int rightHelp = right - 1;
        while (rightHelp > left && arr[rightHelp] == arr[right]) {
          right_count++;
          rightHelp--;
        }
        counter += left_count * right_count;
        left += left_count;
        right -= right_count;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return counter;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; ++i) {
    int num = value - arr[i];
    int *it = std::lower_bound(arr + i + 1, arr + len, num);

    if (it != arr + len && *it == num) {
      int *it_end = std::upper_bound(arr + i + 1, arr + len, num);
      counter += (it_end - it);
    }
  }
  return counter;
}

