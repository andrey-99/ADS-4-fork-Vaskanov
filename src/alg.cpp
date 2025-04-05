// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
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

      int left_orig = left;
      int right_orig = right;

      while (left + 1 < right && arr[left] == arr[left + 1]) {
        countl++;
        left++;
      }
      while (right - 1 > left && arr[right] == arr[right - 1]) {
        countr++;
        right--;
      }
      if (left == right) {
          counter += countl * countr;
      }
      else{
        counter += countl * countr;
      }

      left = left_orig + countl;
      right = right_orig - countr;
      if (left >= right_orig){
          break;
      }
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
  int center;

  while (left <= right) {
    center = left + (right - left) / 2;

    if (arr[center] == num) {
      counter = 1;
      int temp_center = center;

      while (temp_center + 1 < len && arr[temp_center + 1] == num) {
        counter++;
        temp_center++;
      }
      temp_center = center;
      while (temp_center - 1 >= 0 && arr[temp_center - 1] == num) {
        counter++;
        temp_center--;
      }
      return counter;
    } else if (arr[center] > num) {
      right = center - 1;
    } else {
      left = center + 1;
    }
  }
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    counter += searchNum(arr + i + 1, len - i - 1, value - arr[i]);
  }
  return counter;
}

