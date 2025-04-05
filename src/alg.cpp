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
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
}
