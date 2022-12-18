#include <stdio.h>

#define max 8
typedef struct {
    int data[max];
    int head;
    int tail;
} queue;
queue antrian;

void create() {
    antrian.head = antrian.tail = -1;
}

int IsEmpty() {
    if (antrian.tail == -1)
        return 1;
    else
        return 0;
}

int IsFull() {
    if (antrian.tail == max - 1)
        return 1;
    else
        return 0;
}

void enqueue(int data) {
    if (IsEmpty() == 1) {
        antrian.head = antrian.tail = 0;
        antrian.data[antrian.tail] = data;
        printf("%d masuk", antrian.data[antrian.tail]);
    } else {
        if (IsFull() == 0) {
            antrian.tail++;
            antrian.data[antrian.tail] = data;
            printf("%d masuk", antrian.data[antrian.tail]);
        } else {
            printf("antrian penuh");
        }
    }
}

int dequeue() {
    int i;
    int e = antrian.data[antrian.head];
    if (IsEmpty() == 0) {
        if (antrian.head == antrian.tail) {
            antrian.head = antrian.tail = -1;
        } else {
            for (i = antrian.head; i < antrian.tail; i++) {
                antrian.data[i] = antrian.data[i + 1];
            }
            antrian.tail--;
        }
    }
    return e;
}

void clear() {
    antrian.head = antrian.tail = -1;
    printf("antrian kosong");
}

void view() {
    if (IsEmpty() == 1) {
        printf("antrian kosong");
    } else {
        int i;
        for (i = antrian.head; i <= antrian.tail; i++) {
            printf("No. Antri %d: ", i + 1);
            printf("%d", antrian.data[i]);
        }
    }
}

int main() {
    int pil, p=1, data;
    create();
    do {
        printf("\n\nPROGRAM ANTRIAN\n");
        printf("1. Tambah antrian\n");
        printf("2. Panggil antrian\n");
        printf("3. Hapus antrian\n");
        printf("4. Lihat antrian\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pil);
        printf("\n");
        switch (pil) {
            case 1:
                printf("Masukkan data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("Antrian %d dipanggil", dequeue());
                break;
            case 3:
                clear();
                break;
            case 4:
                view();
                break;
            case 5:
                p = 0;
                break;
            default:
                printf("Pilihan tidak ada");
        }
    } while (p == 1);
}