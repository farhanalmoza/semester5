// Program menggunakan bahasa C++
// untuk menyimpan nilai mean, median, dan modus dari sekumpulan data
// yang dimasukkan oleh user kedalam array.

// Created by: Farkhan, Azka AR, Kuncoro A.

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, z;
    float mean, median, modus;
    int data[100];

    cout << "Masukkan banyak data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    cout << endl;
    cout << "Data yang dimasukkan: " << endl;
    for (int j = 0; j < n; j++) {
        cout << data[j] << " ";
    }

    cout << endl;
    cout << endl;

    // Mean
    for (int k = 0; k < n; k++) {
        mean += data[k];
    }

    mean = mean / n;

    cout << "Mean: " << mean << endl;

    // Median
    sort(data, data + n);

    if (n % 2 == 0) {
        median = (data[n / 2 - 1] + data[n / 2]) / 2.0;
    } else {
        median = data[n / 2];
    }

    cout << "Median: " << median << endl;

    // Modus
    int count = 0;
    int max = 0;

    for (int l = 0; l < n; l++) {
        for (int m = 0; m < n; m++) {
            if (data[l] == data[m]) {
                count++;
            }
        }

        if (count > max) {
            max = count;
            z = data[l];
        }

        count = 0;
    }

    cout << "Modus: " << z << endl;

    _getch();
    return 0;
}