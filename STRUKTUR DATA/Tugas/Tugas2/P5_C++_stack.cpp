// Nama : Farkhan
// NPM : 20081010060

#include <stdio.h>
#include <string.h>

#define MAX_STACK 5

typedef struct STACK {
    int data[MAX_STACK];
    int top;
};

STACK tumpukan;

void inisialisasi() {
    tumpukan.top = -1;
}

int IsEmpty() {
    if (tumpukan.top == -1)
        return 1;
    else
        return 0;
}

int IsFull() {
    if (tumpukan.top == MAX_STACK - 1)
        return 1;
    else
        return 0;
}

void push(int data) {
    if (IsFull() == 0) {
        tumpukan.top++;
        tumpukan.data[tumpukan.top] = data;
        printf("%d masuk\n", tumpukan.data[tumpukan.top]);
    } else {
        printf("tumpukan penuh");
    }
}

void pop() {
    int i;
    int e = tumpukan.data[tumpukan.top];
    if (IsEmpty() == 0) {
        if (tumpukan.top == 0) {
            tumpukan.top = -1;
        } else {
            for (i = tumpukan.top; i > 0; i--) {
                tumpukan.data[i] = tumpukan.data[i - 1];
            }
            tumpukan.top--;
        }
    }
}

void clear() {
    tumpukan.top = -1;
    printf("tumpukan kosong\n");
}

void print() {
    if (tumpukan.top == -1) {
        printf("Stack kosong!\n");
    } else {
        printf("\nIsi stack: ");
        for (int i = 0; i <= tumpukan.top; i++) {
            printf("%d ", tumpukan.data[i]);
        }
    }
}

int main() {
    int pilih, data;
    inisialisasi();
    do {
        print();
        printf("\n\n1. Push\n2. Pop\n3. Clear\n4. Lihat\n5. Exit\nPilih: ");
        scanf("%d", &pilih);
        switch (pilih) {
            case 1:
                printf("Masukkan data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                clear();
                break;
            case 4:
                print();
                break;
            case 5:
                printf("Terima kasih");
                break;
            default:
                printf("Pilihan tidak ada");
        }
    } while (pilih != 5);
}