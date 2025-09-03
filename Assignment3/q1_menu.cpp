#include <iostream>
using namespace std;

#define MAXLEN 100
class Stack {
    private:
        int element[MAXLEN];
        int top;
    public:
        // Constructor instead of init.
        Stack() {
            top = -1;
        }
        void init () {
            this->top = -1;
        }
        int isEmpty () {
            return (this->top == -1);
        }
        int isFull () {
            return (this->top == MAXLEN - 1);
        }
        int peep () {
            if (this->isEmpty())
            {
                cout << "Empty Stack" << endl;
                return -1;
            }
            else 
                return this->element[this->top];
        }
        void push (int x) {
            if (this->isFull())
                cout << "OVERFLOW" << endl;
            else
            {
                this->top++;
                this->element[this->top] = x;
            }
        }
        void pop () {
            if (this->isEmpty())
                cout << "UNDERFLOW" << endl;
            else 
                {
                    cout << "Popped: " << this->element[this->top] << endl;
                    this->top--;
                }
        }
        void print () {
            int i;
            cout << "\tPrinting elements of the Stack: " << endl;
            cout << "\t";
            for (i = this->top; i >= 0; i--)
                cout << this->element[i] << " ";
            cout << endl;
        }
};

int main()
{
    int option, n;
    Stack s;
    do
    {
        option = 0;
        cout << "----Choose anyone from the option to begin with Stack----" << endl;
        cout << "1. Create Stack." << endl;
        cout << "2. Push numbers." << endl;
        cout << "3. Peek on top number." << endl;
        cout << "4. Pop the number." << endl;
        cout << "5. Print the stack" << endl;
        cout << "6. Done. Now Exit" << endl;
        cout << "Choose any one of the options (1-6): ";
        cin >> option;
        
        switch (option)
        {
            case 1:
                s.init();
                break;
            case 2:
                cout << "\tEnter the number you want to push: ";
                cin >> n;
                s.push(n);
                break;
            case 3:
                if (s.peep() != -1)
                    cout << "\tPeek: " << s.peep() << endl;
                break;
            case 4:
                s.pop();
                break;
            case 5:
                s.print();
                break;
            case 6:
                break;

            default:
                break;
        }
    } while (option != 6);

    return 0;
}