// buat program single linked list menggunakan bahasa C++
// pada program tersebut terdapat pilihan menu insert, delete, search, dan print
// dapat menggunakan struct

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *head, *tail, *baru, *bantu, *hapus;

void input() {
    baru = new node;
    cout << "Masukkan data : ";
    cin >> baru->data;
    baru->next = NULL;
}

void insertDepan() {
    input();
    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang() {
    input();
    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// insert tengah after number
void insertTengah() {
    input();
    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        int number;
        cout << "Masukkan data setelah : ";
        cin >> number;
        bantu = head;
        while (bantu->data != number) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusDepan() {
    if (head == NULL) {
        cout << "List kosong" << endl;
    } else {
        hapus = head;
        head = hapus->next;
        delete hapus;
    }
}

// hapus data paling belakang
void hapusBelakang() {
    if (head == NULL) {
        cout << "List kosong" << endl;
    } else {
        hapus = head;
        while (hapus->next != tail) {
            hapus = hapus->next;
        }
        bantu = hapus->next;
        hapus->next = NULL;
        tail = hapus;
        delete bantu;
    }
}

// hapus tengah dengan pilihan
void hapusTengah() {
    if (head == NULL) {
        cout << "List kosong" << endl;
    } else {
        int number;
        cout << "Masukkan data yang akan dihapus : ";
        cin >> number;
        hapus = head;
        while (hapus->data != number) {
            hapus = hapus->next;
        }
        bantu = head;
        while (bantu->next != hapus) {
            bantu = bantu->next;
        }
        bantu->next = hapus->next;
        delete hapus;
    }
}

void print() {
    if (head == NULL) {
        cout << "List kosong" << endl;
    } else {
        bantu = head;
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
}

// search data
void search() {
    if (head == NULL) {
        cout << "List kosong" << endl;
    } else {
        int number;
        cout << "Masukkan data yang akan dicari : ";
        cin >> number;
        bantu = head;
        while (bantu->data != number) {
            bantu = bantu->next;

            if (bantu == NULL) {
                cout << "Data tidak ditemukan" << endl;
                return;
            }
        }
        cout << "Data ditemukan" << endl;
    }
}

int main() {
    int pilih;
    do {
        cout << "1. Insert Depan" << endl;
        cout << "2. Insert Belakang" << endl;
        cout << "3. Insert Tengah" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang" << endl;
        cout << "6. Hapus Tengah" << endl;
        cout << "7. Print" << endl;
        cout << "8. Search" << endl;
        cout << "9. Exit" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                insertDepan();
                break;
            case 2:
                insertBelakang();
                break;
            case 3:
                insertTengah();
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                hapusBelakang();
                break;
            case 6:
                hapusTengah();
                break;
            case 7:
                print();
                break;
            case 8:
                search();
                break;
            case 9:
                exit(0);
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
        }
    } while (pilih != 9);
    return 0;
}