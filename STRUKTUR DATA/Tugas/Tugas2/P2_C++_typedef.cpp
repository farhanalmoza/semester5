// Nama : Farkhan
// NPM : 20081010060

#include <stdio.h>
#include <conio.h>

typedef int angka;
typedef float pecahan;
typedef char huruf;

int main() {
    angka umur;
    pecahan ipk;
    huruf nama[10];

    printf("masukkan nama: "); scanf("%s", &nama);
    printf("masukkan umur: "); scanf("%d", &umur);
    printf("masukkan ipk: "); scanf("%f", &ipk);

    printf("\nnama: %s", nama);
    printf("\numur: %d", umur);
    printf("\nipk: %f", ipk);
    getche();

}