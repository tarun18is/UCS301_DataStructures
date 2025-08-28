#include <iostream>
using namespace std;

class DistinctCounter {
public:
    int countDistinct(int arr[], int n) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            bool isDistinct = true;

            // check if arr[i] appeared before
            for (int j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    isDistinct = false;
                    break;
                }
            }

            if (isDistinct)
                count++;
        }

        return count;
    }
};

int main() {
    DistinctCounter obj;

    int arr[] = {10, 20, 10, 30, 40, 20, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Total distinct elements: " << obj.countDistinct(arr, n) << endl;

    return 0;
}
