#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void initRandomizer() {
    srand(time(0));
}

int main() {
    initRandomizer();

    int n;
    cout << "Enter the length of the sequence: ";
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 200 - 100;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int arrMin = 101;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] < arrMin) {
            arrMin = arr[i];
        }
    }

    if (arrMin == 101) {
        cout << "There are no positive values in the sequence." << endl;
    }
    else {
        cout << "The minimum positive value in the sequence is: " << arrMin << endl;
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}