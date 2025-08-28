#include <iostream>
using namespace std;

void deleteDuplicate(int arr[], int *n);
void displayArray(int arr[], int n);

int main() {
    int arr[100];
    int n;

    cout << "Enter the number of elements you want: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    deleteDuplicate(arr, &n);

    cout << "Array after delteting dulplicates: ";
    displayArray(arr, n);

    return 0;
}

void displayArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteDuplicate(int arr[], int* n) 
{
    for (int i = 0; i < *n - 1; i++) 
    {
        for (int j = i + 1; j < *n; j++) 
        {
            if (arr[i] == arr[j])
            {
                // Shift elements to the left to delete duplicate
                for (int k = j; k < *n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                (*n)--;  // decrease size
                j--;     // recheck same index after shifting
            }
        }
    }
    cout << "Deleted all duplicate elements." << endl;
}
