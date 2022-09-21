#include <stdio.h>
#include <conio.h>

int main() {
    // deklarasi struct
    struct mahasiswa {
        char nim[10];
        char nama[10];
        int nilai;
    } mhs[10];

    int i=0;
    int n=0;

    // deskripsi
    printf("masukkan jumlah data: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("\nmasukkan nim: "); scanf("%s", &mhs[i].nim);
        printf("\nmasukkan nama: "); scanf("%s", &mhs[i].nama);
        printf("\nmasukkan nilai: "); scanf("%d", &mhs[i].nilai);
        printf("\n");
    }

    for(i=0; i<n; i++) {
        printf("\nnim: %s", mhs[i].nim);
        printf("\nnama: %s", mhs[i].nama);
        printf("\nnilai: %d", mhs[i].nilai);
        printf("\n");
    }
    getche();
}