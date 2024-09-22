#include <iostream>

using namespace std;

bool areEqual(int a) {
    int bitSize = 8;

    int countOnes = 0;
    int countZeros = 0;

    for (int i = 0; i < bitSize; i++) {
        int mask = 1 << i;
        int a_bit = a & mask;

        if (a_bit != 0) {
            countOnes++;
        }
        else {
            countZeros++;
        }
    }

    cout << "Number of 1s: " << countOnes << endl;
    cout << "Number of 0s: " << countZeros << endl;

    return countOnes > countZeros;
}

int main() {
    int a;

    cout << "Enter your number: ";
    cin >> a;

    if (areEqual(a)) {
        cout << "There are more 1s than 0s in 8-bit representation." << endl;
    }
    else {
        cout << "There are more 0s than 1s or their number is equal in 8-bit representation." << endl;
    }

    return 0;
}