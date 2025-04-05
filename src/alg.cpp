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
            int leftCount = 1;
            int tempLeft = left + 1;
            while (tempLeft <= right && arr[tempLeft] == arr[left]) {
                leftCount++;
                tempLeft++;
            }
            int rightCount = 1;
            int tempRight = right - 1;
            while (tempRight >= left && arr[tempRight] == arr[right]) {
                rightCount++;
                tempRight--;
            }
            counter += leftCount * rightCount;
            left = tempLeft;
            right = tempRight;
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

