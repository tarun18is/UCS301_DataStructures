#include <iostream>

using namespace std;

const int MAX = 100;

class ArrayOperations
{
    private:
        int arr[MAX];
        int size;
    public:
        ArrayOperations() {
            size = 0;
        }

        void create()
        {
            cout << "Enter the number of elements: ";
            cin >> size;

            if (size > MAX || size <= 0)
            {
                cout << "Invalid size!" << endl;
                size = 0;
                return;
            }
            for (int i = 0; i < size; i++)
            {
                cout << "Enter element " << i + 1 << " : ";
                cin >> arr[i];
            }
        }

        void display()
        {
            if(size == 0)
            {
                cout << "You didn't create any array. First create one." << endl;
                return;
            }
    
                cout << "Here is your array: " << endl;
                for (int i = 0; i < size; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            
        }

        void insert()
        {
            if(size == MAX)
            {
                cout << "Array is full. Cannot insert more elements" << endl;
                return;
            }

            int pos, num;

            cout << "Enter position to insert (1 to " << size + 1 << " ): ";
            cin >> pos;

            if (pos < 1 || pos > size + 1)
            {
                cout << "Invalid position!" << endl;
                return;
            }

            cout << "Enter the number you want to add: ";
            cin >> num;
            
            for (int i = size; i > pos-1; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = num;
            size++;
            cout << "Element inserted." << endl;
        }

        void deleteElement()
        {
            if(size == 0)
            {
                cout << "You didn't create any array. First create one." << endl;
                return;
            }

            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;

            if(pos < 1 || pos > size)
            {
                cout << "Invalid position." << endl;
                return;
            }

            for(int i = pos - 1; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "Element deleted." << endl;
        }

        void linearSearch()
        {
            if(size == 0)
            {
                cout << "You didn't create any array. First create one." << endl;
                return;
            }

            int num;
            cout << "Enter the number to be searched: ";
            cin >> num;

            for (int i = 0; i < size; i++)
            {
                if(arr[i] == num)
                {
                    cout << num << " found at position " << i + 1 << "." << endl;
                    return;
                }
            }
            cout << "Not found:(" << endl;
        }
};

int main() {
    ArrayOperations array;
    int choice;

    do
    {
        cout << "------Menu------" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Choose the action you want to perform:";
        cin >> choice;
        
        switch (choice)
        {
            case 1: array.create();
                break;
            case 2: array.display();
                break;
            case 3: array.insert();
                break;
            case 4: array.deleteElement();
                break;
            case 5: array.linearSearch();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid input.." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}