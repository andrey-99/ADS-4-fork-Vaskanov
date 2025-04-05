// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  return counter;
}

int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  int countr;
  int countl;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    if (arr[left] + arr[right] == value) {
      countl = 1;
      countr = 1;
      while (arr[left] == arr[left + 1] && left + 1 < right) {
        countl++;
        left++;
      }
      while (arr[right] == arr[right - 1] && right - 1 > left) {
        countr++;
        right--;
      }
      counter += countl * countr;
      left++;
      right--;
    } else if (arr[left] + arr[right] > value) {
      right--;
    } else {
      left++;
    }
  }
  return counter;
}

int searchNum(int *arr, int len, int num) {
  int counter = 0;
  int left = 0;
  int right = len - 1;
  int center = left + (right - left) / 2;
  while (left <= right) {
    if (arr[center] == num) {
      counter++;
      while (arr[center + 1] == num && center + 1 < len) {
        center++;
      }
      while (arr[center - 1] == num && center - 1 >= 0) {
        counter++;
        center--;
      }
      break;
    } else if (arr[center] > num) {
      right = center - 1;
      center = left + (right - left) / 2;
    } else {
      left = center + 1;
      center = left + (right - left) / 2;
    }
  }
  return counter;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    counter += searchNum(arr + i + 1, len - i - 1, value - arr[i]);
  }
  return counter;
}
