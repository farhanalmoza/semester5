// Nama : Farkhan
// NPM : 20081010060

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

struct node {
    char nim[20], nama[20];
    int umur;
    node *next;
} mhs, *baru, *head=NULL, *tail=NULL, *bantu, *hapus;

void input_data() {
    baru = (node*)malloc(sizeof(struct node));
    cout << "Masukkan NIM : ";
    cin >> baru->nim;
    cout << "Masukkan Nama : ";
    cin >> baru->nama;
    cout << "Masukkan Umur : ";
    cin >> baru->umur;
    baru->next = NULL;
}

void clrscr() {
    system("cls");
}

void tambah_belakang() {
    input_data();
    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void tambah_depan() {
    input_data();
    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void hapus_belakang() {
    if (head == NULL) {
        cout << "Data masih kosong";
    } else if (head->next == NULL) {
        hapus = head;
        head = NULL;
        tail = NULL;
        free(hapus);
    } else {
        bantu = head;
        while (bantu->next->next != NULL) {
            bantu = bantu->next;
        }
        hapus = tail;
        tail = bantu;
        bantu->next = NULL;
        free(hapus);
    }
}

void hapus_depan() {
    if (head == NULL) {
        cout << "Data masih kosong";
    } else if (head->next == NULL) {
        hapus = head;
        head = NULL;
        tail = NULL;
        free(hapus);
    } else {
        hapus = head;
        head = head->next;
        free(hapus);
    }
}

void tampil_data() {
    if (head == NULL) {
        cout << "Data masih kosong";
    } else {
        bantu = head;
        while (bantu != NULL) {
            cout << "NIM : " << bantu->nim << endl;
            cout << "Nama : " << bantu->nama << endl;
            cout << "Umur : " << bantu->umur << endl;
            bantu = bantu->next;
        }
    }
}

int main() {
    int pilih;
    char ulang;
    do {
        clrscr();
        cout << "Menu : " << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampil Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                tambah_depan();
                break;
            case 2:
                tambah_belakang();
                break;
            case 3:
                hapus_depan();
                break;
            case 4:
                hapus_belakang();
                break;
            case 5:
                tampil_data();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Pilihan tidak ada";
                break;
        }
        cout << endl << "Kembali ke menu (y/n) : ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
    return 0;
}