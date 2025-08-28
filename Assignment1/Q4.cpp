#include <iostream>

using namespace std;

void displayArray(int arr[], int n);
void reverseArray(int A[], int n);

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ans;

    // Print the default array
    cout << "Your array is: ";
    displayArray(arr, 10);

    cout << "----Choose----" << endl;
    cout << "1. Reverse the elements of an array." << endl;
    cout << "2. Find the matrix multiplication." << endl;
    cout << "3. Find the transpose of the matrix." << endl;
    cout << "What action do you want to perform(1-3): ";
    cin >> ans;

    switch (ans)
    {
    case 1:
        reverseArray(arr, 10);
        break;
    
    default:
        break;
    }
}

void displayArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    
    cout << endl;
}

void reverseArray(int A[], int n)
{
    cout << "Array in reverse order: ";
    for (int i = n - 1; i >= 0; i--)
        cout << A[i] << " ";

    cout << endl;
}