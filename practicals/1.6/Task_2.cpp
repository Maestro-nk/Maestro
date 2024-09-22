#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void xorSeq(const vector<int>& A, const vector<int>& B, vector<int>& C) {
    for (size_t i = 0; i < A.size(); i++) {
        C[i] = A[i] ^ B[i];
    }
}

int main() {
    int n;
    srand(static_cast<unsigned>(time(0)));

    cout << "Enter the length of the sequences: ";
    cin >> n;

    vector<int> A(n), B(n);

    cout << "First sequence: ";
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 2;
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Second sequence: ";
    for (int i = 0; i < n; i++) {
        B[i] = rand() % 2;
        cout << B[i] << " ";
    }
    cout << endl;

    vector<int> C(n);
    xorSeq(A, B, C);

    cout << "Result of XOR operation: ";
    for (int bit : C) {
        cout << bit << " ";
    }
    cout << endl;

    return 0;
}
