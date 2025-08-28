#include <iostream>
using namespace std;

class BubbleSort
{
private:
    int arr[100];
    int n;

public:
    BubbleSort(int inputArr[], int size)
    {
        n = size;
        for (int i = 0; i < n; i++)
            arr[i] = inputArr[i];
    }

    void sort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    // swap 
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    int inputArr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(inputArr) / sizeof(inputArr[0]);

    BubbleSort bs(inputArr, size);

    cout << "Unsorted array: ";
    bs.display();

    bs.sort();

    cout << "Sorted array:   ";
    bs.display();

    return 0;
}
