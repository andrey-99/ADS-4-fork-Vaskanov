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
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        counter += n * (n - 1) / 2;
        break;
      } else {
        int leftCount = 1;
        int rightCount = 1;
        int tempLeft = left;
        while (tempLeft + 1 <= right && arr[tempLeft] == arr[tempLeft + 1]) {
          leftCount++;
          tempLeft++;
        }
        int tempRight = right;
        while (tempRight - 1 >= left && arr[tempRight] == arr[tempRight - 1]) {
          rightCount++;
          tempRight--;
        }
        counter += leftCount * rightCount;
        left = tempLeft + 1;
        right = tempRight - 1;
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
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        int count = 1;
        int tempLeft = mid - 1;
        while (tempLeft >= i + 1 && arr[tempLeft] == target) {
          count++;
          tempLeft--;
        }
        int tempRight = mid + 1;
        while (tempRight < len && arr[tempRight] == target) {
          count++;
          tempRight++;
        }
        counter += count;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return counter;
}

