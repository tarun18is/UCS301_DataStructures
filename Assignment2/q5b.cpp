// Tri diagnol matrix
#include <iostream>
using namespace std;

class TriDiagonal {
    int *A;
    int n;
public:
    TriDiagonal(int size) {
        n = size;
        A = new int[3*n - 2];
        for (int i = 0; i < 3*n-2; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i - j == 1) A[i-2] = x;          // lower
        else if (i - j == 0) A[n-1+i-1] = x; // main
        else if (i - j == -1) A[2*n-1+i-1] = x; // upper
    }
    int get(int i, int j) {
        if (i - j == 1) return A[i-2];
        else if (i - j == 0) return A[n-1+i-1];
        else if (i - j == -1) return A[2*n-1+i-1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};
