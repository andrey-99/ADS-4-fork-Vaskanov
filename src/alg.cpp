// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  int left = 0;
  int right = len;
  while (left < right) {
    if (left + right == value) {
      counter++;
      left++;
      right--;
    } else if (left + right > value) {
      right--;
    } else {
      left++;
    }
  return counter;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
}
