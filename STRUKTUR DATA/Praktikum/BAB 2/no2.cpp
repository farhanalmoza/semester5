// buat program double linked list menggunakan bahasa C++
// pada program tersebut terdapat pilihan menu insert, delete, search, dan print
// dapat menggunakan struct.

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

node *head, *tail, *baru, *bantu, *hapus;

void input() {
    baru = new node;
    cout << "Masukkan data : ";
    cin >> baru->data;
    baru->next = NULL;
    baru->prev = NULL;
}

void insertDepan() {
    input();
    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
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
        baru->prev = tail;
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
        baru->prev = bantu;
        bantu->next = baru;
        baru->next->prev = baru;
    }
}

void hapusDepan() {
    if (head == NULL) {
        cout << "List kosong" << endl;
    } else if (head->next == NULL) {
        hapus = head;
        head = NULL;
        tail = NULL;
        delete hapus;
    } else {
        hapus = head;
        head = head->next;
        head->prev = NULL;
        delete hapus;
    }
}

void hapusBelakang() {
    if (head == NULL) {
        cout << "List kosong" << endl;
    } else if (head->next == NULL) {
        hapus = head;
        head = NULL;
        tail = NULL;
        delete hapus;
    } else {
        hapus = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete hapus;
    }
}

void hapusTengah() {
    if (head == NULL) {
        cout << "List kosong" << endl;
    } else if (head->next == NULL) {
        hapus = head;
        head = NULL;
        tail = NULL;
        delete hapus;
    } else {
        int number;
        cout << "Masukkan data yang akan dihapus : ";
        cin >> number;
        bantu = head;
        while (bantu->data != number) {
            bantu = bantu->next;
        }
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
        delete bantu;
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
        cout << "2. Insert Tengah" << endl;
        cout << "3. Insert Belakang" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Tengah" << endl;
        cout << "6. Hapus Belakang" << endl;
        cout << "7. Print" << endl;
        cout << "8. Search" << endl;
        cout << "9. Exit" << endl;
        cout << "Pilih : "; cin >> pilih;

        switch (pilih) {
            case 1: insertDepan(); break;
            case 2: insertTengah(); break;
            case 3: insertBelakang(); break;
            case 4: hapusDepan(); break;
            case 5: hapusTengah(); break;
            case 6: hapusBelakang(); break;
            case 7: print(); break;
            case 8: search(); break;
        }
    } while (pilih != 9);

    return 0;
}