// Nama : Farkhan
// NPM : 20081010060

#include <stdio.h>
#include <conio.h>

int pangkat(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * pangkat(a, b - 1);
    }
}

int main() {
    int a, b;
    printf("masukkan angka: "); scanf("%d", &a);
    printf("masukkan pangkat: "); scanf("%d", &b);
    printf("%d pangkat %d = %d", a, b, pangkat(a, b));
    getche();
}