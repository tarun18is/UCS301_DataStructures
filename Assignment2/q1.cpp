#include <iostream>

using namespace std;

class BinarySerch 
{
    private:
        int arr[100];
        int n;

    public:
        BinarySerch(int inputArray[], int size)
        {
            n = size;
            for (int i = 0; i < n; i++)
                arr[i] = inputArray[i];
        }

        void display()
        {
            cout << "Array elements: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        int search(int key)
        {
            int low = 0, high = n - 1;
            while(low <= high)
            {
                int mid = (low + high) / 2;

                if (arr[mid] == key)
                    return mid + 1;
                
                else if (arr[mid] < key)
                    low = mid + 1;
                else 
                    high = mid - 1;
            }
            return -1;
        }
};

int main()
{
    int inputArr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int size = sizeof(inputArr) / sizeof(inputArr[0]);

    BinarySerch bs(inputArr, size);

    bs.display();

    int key;
    cout << "Enter the element you want to search: ";
    cin >> key;

    int result = bs.search(key);

    if(result != -1)
        cout << "Element found at position " << result << endl;
    else
        cout << "Not found." << endl;

    return 0;
}