// buat program matriks 3x3 menggunakan bahasa C++
// dan invers matriks tersebut
// Created by: Farkhan, Azka AR, Kuncoro A.

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
    int matriks[3][3];
    int matriksInvers[3][3];
    int determinan;
    int temp;

    cout << "Masukkan nilai matriks: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriks[i][j];
        }
    }

    cout << endl;
    cout << "Matrix yang dimasukkan: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Determinan
    determinan = (matriks[0][0] * matriks[1][1] * matriks[2][2]) + (matriks[0][1] * matriks[1][2] * matriks[2][0]) + (matriks[0][2] * matriks[1][0] * matriks[2][1]) - (matriks[0][2] * matriks[1][1] * matriks[2][0]) - (matriks[0][1] * matriks[1][0] * matriks[2][2]) - (matriks[0][0] * matriks[1][2] * matriks[2][1]);

    cout << "Determinan: " << determinan << endl;

    // Matriks Invers
    matriksInvers[0][0] = (matriks[1][1] * matriks[2][2]) - (matriks[1][2] * matriks[2][1]);
    matriksInvers[0][1] = (matriks[0][2] * matriks[2][1]) - (matriks[0][1] * matriks[2][2]);
    matriksInvers[0][2] = (matriks[0][1] * matriks[1][2]) - (matriks[0][2] * matriks[1][1]);
    matriksInvers[1][0] = (matriks[1][2] * matriks[2][0]) - (matriks[1][0] * matriks[2][2]);
    matriksInvers[1][1] = (matriks[0][0] * matriks[2][2]) - (matriks[0][2] * matriks[2][0]);
    matriksInvers[1][2] = (matriks[0][2] * matriks[1][0]) - (matriks[0][0] * matriks[1][2]);
    matriksInvers[2][0] = (matriks[1][0] * matriks[2][1]) - (matriks[1][1] * matriks[2][0]);
    matriksInvers[2][1] = (matriks[0][1] * matriks[2][0]) - (matriks[0][0] * matriks[2][1]);
    matriksInvers[2][2] = (matriks[0][0] * matriks[1][1]) - (matriks[0][1] * matriks[1][0]);

    cout << "Matriks Invers: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriksInvers[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Matriks Invers dibagi determinan
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriksInvers[i][j] = matriksInvers[i][j] / determinan;
        }
    }

    cout << "Matriks Invers dibagi determinan: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriksInvers[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    getch();
    return 0;
}