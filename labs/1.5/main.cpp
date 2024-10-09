/**
* Student Name: Torgoniy Bogdan
* Student Group: 123
* Lab 1.5
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    {
        float a = 54.9;
        float b = 82.1;
        int c = 74;
        int d = 74;

        bool res1 = !(!(a <= b) || (c == d));
        cout << "res1: " << boolalpha << res1 << endl;
    }
    {
        int a = 49;
        int b = 58;
        float c = 8.8;
        float d = 6.6;

        bool res2 = !(!(a <= b) || (c == d));
        cout << "res2: " << boolalpha << res2 << endl;
    }
    {
        int a = 41;
        int b = -13;
        int c = 22;
        int d = -593;
        int e = 12;
        float f;

        f = (a & +b) / c > (d + e) << (sizeof(float) * 8);

        std::cout << "Result: " << f << std::endl;
    }
}