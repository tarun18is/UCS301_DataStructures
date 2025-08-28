#include <iostream>
using namespace std;

class InversionCounter {
public:
    int countInversionsBruteForce(int arr[], int n) {
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j])
                    count++;
            }
        }
        return count;
    }

    int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
        int i = left;     
        int j = mid + 1;  
        int k = left;     
        int invCount = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                invCount += (mid - i + 1); 
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (i = left; i <= right; i++) arr[i] = temp[i];

        return invCount;
    }

    int mergeSortAndCount(int arr[], int temp[], int left, int right) {
        int invCount = 0;
        if (left < right) {
            int mid = (left + right) / 2;
            invCount += mergeSortAndCount(arr, temp, left, mid);
            invCount += mergeSortAndCount(arr, temp, mid + 1, right);
            invCount += mergeAndCount(arr, temp, left, mid, right);
        }
        return invCount;
    }

    int countInversionsMergeSort(int arr[], int n) {
        int* temp = new int[n];
        int result = mergeSortAndCount(arr, temp, 0, n - 1);
        delete[] temp;
        return result;
    }
};

int main() {
    InversionCounter obj;

    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Inversions (Brute Force): " << obj.countInversionsBruteForce(arr, n) << endl;

    int arr2[] = {2, 4, 1, 3, 5};
    cout << "Inversions (Merge Sort): " << obj.countInversionsMergeSort(arr2, n) << endl;

    return 0;
}
