#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void initRandomiser() {
    srand(time(0));
}

int find_first_occurrence(const vector<int>& A, int P) {
    for (size_t i = 0; i < A.size(); i++) {
        if (A[i] == P) {
            return i;
        }
    }
    return -1;
}

int main() {
    initRandomiser();

    int n, P;
    cout << "Enter the length of the sequence: ";
    cin >> n;
    cout << "Enter the value of the element you are looking for: ";
    cin >> P;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100 - 50;
    }

    cout << "Generated sequence: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    int index = find_first_occurrence(A, P);

    if (index != -1) {
        cout << "First occurrence of P in the sequence A: index " << index << endl;
    }
    else {
        cout << "The value of P is not found in the sequence A" << endl;
    }

    return 0;
}