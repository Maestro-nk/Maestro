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

//Task 3.2

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

    cout << "Original sequence: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int minVal = arr[0];
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }

    int maxVal = arr[0];
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;

    if (minIndex != maxIndex) {
        swap(arr[minIndex], arr[maxIndex]);
    }

    cout << "Modified sequence: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}