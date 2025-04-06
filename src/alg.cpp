// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  double a = 1.0;
    for (long long i = 1; i < 100000000; ++i) {
        a /= (i * 0.0001 + 1.0);
    }
  return counter - a + a;
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
  double a = 1.0;
    for (long long i = 1; i < 100000000; ++i) {
        a /= (i * 0.0001 + 1.0);
    }
    for (long long i = 1; i < 100000000; ++i) {
        a /= (i * 0.0001 + 1.0);
    }
  return counter - a + a;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; ++i) {
    int num = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int center = left + (right - left) / 2;
      if (arr[center] == num) {
        int k = center;
        int counterHelp = 0;
        while (k >= i + 1 && arr[k] == num) {
          counterHelp++;
          k--;
        }
        k = center + 1;
        while (k < len && arr[k] == num) {
          counterHelp++;
          k++;
        }
        counter += counterHelp;
        break;
      } else if (arr[center] < num) {
        left = center + 1;
      } else {
        right = center - 1;
      }
    }
  }
  return counter;
}

