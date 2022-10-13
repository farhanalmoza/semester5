// Nama : Farkhan
// NPM : 20081010060

// buat program rekursif untuk menampilkan deret fibonaci
#include <iostream>
using namespace std;

int fibonaci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonaci(n - 1) + fibonaci(n - 2);
    }
}

int main() {
    int n;
    cout << "masukkan angka: "; cin >> n;
    cout << "fibonaci ke-" << n << " adalah " << fibonaci(n) << endl;


    for (int i = 0; i < n; i++) {
        cout << fibonaci(i) << " ";
    }

    return 0;
}