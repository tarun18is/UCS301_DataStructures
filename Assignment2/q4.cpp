#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class StringOperations
{
public:
    // (a) Concatenate two strings
    void concatenate(string str1, string str2)
    {
        cout << "Concatenated String: " << str1 + str2 << endl;
    }

    // (b) Reverse a string
    void reverseString(string str)
    {
        reverse(str.begin(), str.end());
        cout << "Reversed String: " << str << endl;
    }

    // (c) Delete all vowels from a string
    void deleteVowels(string str)
    {
        string result = "";
        for (char c : str)
        {
            char lower = tolower(c);
            if (!(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'))
                result += c;
        }
        cout << "String without vowels: " << result << endl;
    }

    // (d) Sort multiple strings in alphabetical order
    void sortStrings(string arr[], int n)
    {
        sort(arr, arr + n);
        cout << "Strings in alphabetical order:\n";
        for (int i = 0; i < n; i++)
            cout << arr[i] << endl;
    }

    // (e) Convert a character from uppercase to lowercase
    void upperToLower(char ch)
    {
        if (isupper(ch))
            cout << "Lowercase: " << (char)tolower(ch) << endl;
        else
            cout << "Entered character is not uppercase!" << endl;
    }
};

int main()
{
    StringOperations obj;

    obj.concatenate("Hello ", "World");

    obj.reverseString("OpenAI");

    obj.deleteVowels("Beautiful Day");

    string arr[] = {"Banana", "Apple", "Mango", "Cherry"};
    int n = sizeof(arr) / sizeof(arr[0]);
    obj.sortStrings(arr, n);

    obj.upperToLower('G');

    return 0;
}
