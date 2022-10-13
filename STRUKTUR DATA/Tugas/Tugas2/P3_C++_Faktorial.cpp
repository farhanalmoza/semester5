// Nama : Farkhan
// NPM : 20081010060

// buat program rekursif untuk faktorial
#include <iostream>
using namespace std;

int faktorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int n;
    cout << "masukkan angka: "; cin >> n;
    cout << "faktorial dari " << n << " adalah " << faktorial(n) << endl;

    return 0;
}