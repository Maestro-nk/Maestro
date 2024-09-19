#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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

    int* minVal = min_element(arr, arr + n);
    int* maxVal = max_element(arr, arr + n);

    cout << "Min: " << *minVal << endl;
    cout << "Max: " << *maxVal << endl;

    if (minVal != maxVal) {
        swap(*minVal, *maxVal);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    delete[] arr;
    arr = nullptr;

    return 0;
}