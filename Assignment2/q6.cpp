#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

class SparseMatrix {
public:
    Element data[100];
    int rows, cols, terms;

    SparseMatrix(int r = 0, int c = 0, int t = 0) {
        rows = r;
        cols = c;
        terms = t;
    }

    void display() {
        cout << "Row  Col  Value\n";
        for (int i = 0; i < terms; i++) {
            cout << data[i].row << "    " << data[i].col << "    " << data[i].val << endl;
        }
    }

    // (a) Transpose
    SparseMatrix transpose() {
        SparseMatrix result(cols, rows, terms);
        int k = 0;
        for (int c = 0; c < cols; c++) {
            for (int i = 0; i < terms; i++) {
                if (data[i].col == c) {
                    result.data[k].row = data[i].col;
                    result.data[k].col = data[i].row;
                    result.data[k].val = data[i].val;
                    k++;
                }
            }
        }
        return result;
    }

    // (b) Addition
    SparseMatrix add(SparseMatrix B) {
        SparseMatrix result(rows, cols, 0);
        int i = 0, j = 0, k = 0;

        while (i < terms && j < B.terms) {
            if (data[i].row < B.data[j].row ||
               (data[i].row == B.data[j].row && data[i].col < B.data[j].col)) {
                result.data[k++] = data[i++];
            }
            else if (B.data[j].row < data[i].row ||
                    (B.data[j].row == data[i].row && B.data[j].col < data[i].col)) {
                result.data[k++] = B.data[j++];
            }
            else { 
                result.data[k].row = data[i].row;
                result.data[k].col = data[i].col;
                result.data[k].val = data[i].val + B.data[j].val;
                i++; j++; k++;
            }
        }

        while (i < terms) result.data[k++] = data[i++];
        while (j < B.terms) result.data[k++] = B.data[j++];

        result.terms = k;
        return result;
    }

    // (c) Multiplication
    SparseMatrix multiply(SparseMatrix B) {
        SparseMatrix result(rows, B.cols, 0);

        for (int i = 0; i < terms; i++) {
            for (int j = 0; j < B.terms; j++) {
                if (data[i].col == B.data[j].row) {
                    int r = data[i].row;
                    int c = B.data[j].col;
                    int v = data[i].val * B.data[j].val;

                    // check if already present
                    bool found = false;
                    for (int k = 0; k < result.terms; k++) {
                        if (result.data[k].row == r && result.data[k].col == c) {
                            result.data[k].val += v;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        result.data[result.terms].row = r;
                        result.data[result.terms].col = c;
                        result.data[result.terms].val = v;
                        result.terms++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    SparseMatrix A(3, 3, 3);
    A.data[0] = {0, 0, 5};
    A.data[1] = {1, 1, 8};
    A.data[2] = {2, 2, 3};

    SparseMatrix B(3, 3, 3);
    B.data[0] = {0, 1, 6};
    B.data[1] = {1, 1, 7};
    B.data[2] = {2, 0, 4};

    cout << "Matrix A (triplet form):\n";
    A.display();

    cout << "\nMatrix B (triplet form):\n";
    B.display();

    cout << "\nTranspose of A:\n";
    SparseMatrix T = A.transpose();
    T.display();

    cout << "\nA + B (Addition):\n";
    SparseMatrix S = A.add(B);
    S.display();

    cout << "\nA * B (Multiplication):\n";
    SparseMatrix M = A.multiply(B);
    M.display();

    return 0;
}
