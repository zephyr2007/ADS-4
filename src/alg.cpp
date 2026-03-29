#include "alg.h"

int countPairsA(int *array, int length, int target) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[i] + array[j] == target) {
                result++;
                while (j + 1 < length && array[j] == array[j + 1]) {
                    j++;
                }
            }
        }
        while (i + 1 < length && array[i] == array[i + 1]) {
            i++;
        }
    }
    return result;
}

int countPairsB(int *array, int length, int target) {
    int result = 0;
    for (int k = 0; k < length; k++) {
        int needed = target - array[k];
        int left = k + 1;
        int right = length - 1;
        int found = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == needed) {
                found = mid;
                break;
            } else if (array[mid] < needed) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (found != -1) {
            result++;
            while (k + 1 < length && array[k] == array[k + 1]) {
                k++;
            }
        }
    }
    return result;
}

int countPairsC(int *array, int length, int target) {
    int result = 0;
    int start = 0;
    int finish = length - 1;

    while (start < finish) {
        int sum = array[start] + array[finish];
        if (sum == target) {
            result++;
            int startVal = array[start];
            while (start < finish && array[start] == startVal) {
                start++;
            }
            int finishVal = array[finish];
            while (start <= finish && array[finish] == finishVal) {
                finish--;
            }
        } else if (sum < target) {
            start++;
        } else {
            finish--;
        }
    }
    return result;
}
