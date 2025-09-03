#include <iostream>
using namespace std;

#define MAXLEN 100

class Stack {
    private:
        string element;
        int top;
    public:
        Stack() {
            top = -1;
        }
        int isEmpty() {
            return (this->top == -1);
        }
        int isFull() {
            return (this->top == MAXLEN - 1);
        }
        void push (string x) {
            if (this->isFull())
                cout << "OVERFLOW" << endl;
            else 
            {
                for (int i = 0; i < x.length(); i++)
                {
                    this->top++;
                    this->element[this->top] = x[i];
                }    
            }
        }
        void print () {
            int i;
            cout << "Printing in reverse order: ";
            for (i = this->top; i >= 0; i--)
            {
                cout << this->element[i];
            }
            cout << endl;
        }
};

int main()
{
    string input;
    Stack s;

    cout << "Input the string: ";
    getline(cin, input);

    s.push(input);

    s.print();
    return 0;
}