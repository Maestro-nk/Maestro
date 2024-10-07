#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <fstream>

std::string red = "\033[31m";
std::string purple = "\033[35m";
std::string yellow = "\033[33m";
std::string blue = "\033[34m";
std::string dGreen = "\033[32m";
std::string brown = "\033[33;48;5;94m";
std::string reset = "\033[0m";

std::string symb[] = { "#", "@", "&", "$" };
std::string cols[] = { red, purple, yellow, blue };
std::string symbColArr[4][4];

void randSymbColArr() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::string randSymb = symb[rand() % 4];
            std::string randCol = cols[rand() % 4];
            symbColArr[i][j] = randCol + randSymb;
        }
    }
}

const int CONSOLE_W = 125;

void printTri(int h, int off, std::ofstream& outFile) {
    int w = 2 * h - 1;
    std::vector<std::vector<std::string>> tri(h, std::vector<std::string>(w + off, " "));

    for (int i = 0; i < h; ++i) {
        int stars = 2 * i + 1;
        int start = (w - stars) / 2 + off;
        for (int j = 0; j < stars; ++j) {
            tri[i][start + j] = dGreen + "*";
        }
    }

    int totalStars = 0;
    for (int i = 0; i < h; ++i) {
        totalStars += (2 * i + 1);
    }
    int repCount = static_cast<int>(totalStars * 0.5);

    for (int n = 0; n < repCount; ++n) {
        int i = rand() % h;
        int j = rand() % (2 * i + 1);

        int symbIndex = (w - (2 * i + 1)) / 2 + j + off;
        tri[i][symbIndex] = symbColArr[rand() % 4][rand() % 4];
    }

    for (const auto& row : tri) {
        for (const auto& ch : row) {
            std::cout << ch;
            outFile << ch;
        }
        std::cout << std::endl;
        outFile << std::endl;
    }
}

void printtrunk(int off, std::ofstream& outFile) {
    std::string sep = brown + "|" + reset;
    std::cout << std::string(off, ' ') << sep << std::endl;
    outFile << std::string(off, ' ') << sep << std::endl;
}

void printMultiTri(int initH, int count, std::ofstream& outFile) {
    int totalH = initH;
    int maxTriW = 2 * (initH + count - 1) - 1;

    for (int i = 0; i < count; ++i) {
        int off = (CONSOLE_W - maxTriW) / 2 - i;

        printTri(totalH, off, outFile);
        totalH++;
    }

    int lastOff = ((CONSOLE_W - 1) / 2 - (maxTriW / 2)) + 2;
    printtrunk(lastOff, outFile);
}

int main() {
    int initH = 3;
    int numTri;

    srand(static_cast<unsigned>(time(0)));

    std::cout << "Enter the number of triangles: ";
    std::cin >> numTri;

    std::ofstream outFile("output.txt");

    for (int iter = 0; iter < 10; ++iter) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        randSymbColArr();

        printMultiTri(initH, numTri, outFile);

        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    outFile.close();

    std::cout << "File 'output.txt' has been successfully saved." << std::endl;

    return 0;
}
