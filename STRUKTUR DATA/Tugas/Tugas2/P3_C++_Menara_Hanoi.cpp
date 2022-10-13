// Nama : Farkhan
// NPM : 20081010060

// buat program rekursif untuk menara hanoi
#include <iostream>
using namespace std;

void menara(int n, char awal, char akhir, char bantu) {
    if (n == 1) {
        cout << "pindahkan cakram 1 dari " << awal << " ke " << akhir << endl;
    } else {
        menara(n - 1, awal, bantu, akhir);
        cout << "pindahkan cakram " << n << " dari " << awal << " ke " << akhir << endl;
        menara(n - 1, bantu, akhir, awal);
    }
}

int main() {
    int n;
    cout << "masukkan jumlah cakram: "; cin >> n;
    menara(n, 'A', 'C', 'B');

    return 0;
}