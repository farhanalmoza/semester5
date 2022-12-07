// FINAL PROJECT UTS STRUKTUR DATA KELOMPOK 5
// Farkhan 20081010060
// Azka Avicenna Rasjid 20081010115
// Kuncoro Ariadi 20081010098

// Program pendataan komik di gudang

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct node {
    int kode_komik, tahun;
    char judul[50], penerbit[50], pengarang[50];
    struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;

void tambah() {
    int kode_komik;
    char judul[50];
    char penerbit[50];
    char pengarang[50];
    int tahun;

    cout << ">> Masukkan Kode Komik		: "; cin >> kode_komik;
    cout << ">> Masukkan Judul Komik		: "; cin >> judul;
    cout << ">> Masukkan Penerbit Komik	: "; cin >> penerbit;
    cout << ">> Masukkan Pengarang Komik	: "; cin >> pengarang;
    cout << ">> Masukkan Tahun Terbit Komik	: "; cin >> tahun;

    if (rear == NULL) {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->next = NULL;
        rear->kode_komik = kode_komik;
        strcpy(rear->judul, judul);
        strcpy(rear->penerbit, penerbit);
        strcpy(rear->pengarang, pengarang);
        rear->tahun = tahun;
        front = rear;
    } else {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->next = temp;
        temp->kode_komik = kode_komik;
        strcpy(temp->judul, judul);
        strcpy(temp->penerbit, penerbit);
        strcpy(temp->pengarang, pengarang);
        temp->tahun = tahun;
        temp->next = NULL;
        rear = temp;
    }
    cout << "\nKomik Berhasil Ditambahkan" << endl << endl;
}

void kirim() {
    temp = front;
    if (front == NULL) {
        cout << "Gudang kosong, masukkan data komik terlebih dahulu..." << endl;
        return;
    } else if (temp->next != NULL) {
        temp = temp->next;
        cout << "Komik yang dikirim ke toko adalah : " << front->judul << endl;
        free(front);
        front = temp;
    } else {
        cout << "Komik yang dikirim ke toko adalah : " << front->judul << endl;
        free(front);
        front = NULL;
        rear = NULL;
    }
}

void tampil() {
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
        cout<<"Gudang kosong, masukkan data komik terlebih dahulu..."<<endl << endl;
        return;
    }
    int i = 1;
    cout << "Data komik yang tersedia : " << endl << endl;
    while (temp != NULL) {
    	cout << "[ Data Komik Ke-" << i << " ]"<< endl;
        cout << "Kode Komik		: " << temp->kode_komik << endl;
        cout << "Judul Komik		: " << temp->judul << endl;
        cout << "Penerbit Komik		: " << temp->penerbit << endl;
        cout << "Pengarang Komik		: " << temp->pengarang << endl;
        cout << "Tahun Terbit Komik	: " << temp->tahun << endl << endl;
        i++;
        temp = temp->next;
    }
    cout<<endl;
}

void cari() {
    int kode_komik;
    int flag = 0;
    temp = front;
    if (temp == NULL) {
        cout << "Gudang kosong, masukkan data komik terlebih dahulu..." << endl;
        return;
    }
    cout << "Masukkan Kode Komik : ";
    cin >> kode_komik;
    while (temp != NULL) {
        if (temp->kode_komik == kode_komik) {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1) {
        cout << "\nKode Komik		: " << temp->kode_komik << endl;
        cout << "Judul Komik		: " << temp->judul << endl;
        cout << "Penerbit Komik		: " << temp->penerbit << endl;
        cout << "Pengarang Komik		: " << temp->pengarang << endl;
        cout << "Tahun Terbit Komik	: " << temp->tahun << endl;
    } else {
        cout << "Kode Komik tidak ditemukan..." << endl;
    }

    cout << endl;
}

void hapus() {
    int kode_komik;
    int flag = 0;
    struct node *temp1;
    temp = front;
    if (temp == NULL) {
        cout << "Gudang kosong, masukkan data komik terlebih dahulu..." << endl;
        return;
    }
    cout << "Masukkan Kode Komik : ";
    cin >> kode_komik;
    while (temp != NULL) {
        if (temp->kode_komik == kode_komik) {
            flag = 1;
            break;
        }
        temp1 = temp;
        temp = temp->next;
    }
    if (flag == 1) {
        if (temp == front) {
            if (temp->next != NULL) {
                temp = temp->next;
                cout << "Komik yang dihapus adalah : " << front->judul << endl;
                free(front);
                front = temp;
            } else {
                cout << "Komik yang dihapus adalah : " << front->judul << endl;
                free(front);
                front = NULL;
                rear = NULL;
            }
        } else if (temp->next == NULL) {
            rear = temp1;
            rear->next = NULL;
            cout << "Komik yang dihapus adalah : " << temp->judul << endl;
            free(temp);
        } else {
            temp1->next = temp->next;
            cout << "Komik yang dihapus adalah : " << temp->judul << endl;
            free(temp);
        }
    } else {
        cout << "Kode Komik tidak ditemukan" << endl;
    }

    cout << endl;
}

int main() {
    int pilihan;
    
    cout << "=================================================" << endl;
	cout << "=== Program Pendataan Komik Pada Suatu Gudang ===" << endl; 
	cout << "=================================================" << endl << endl;
	
	cout << "DISUSUN OLEH KELOMPOK 5 " << endl;
	cout << "Azka Avicenna Rasjid	[20081010115]" << endl;
	cout << "Farkhan			[20081010060]" << endl;
	cout << "Kuncoro Ariadi		[20081010096]" << endl << endl;
	
    do {
        cout << "Pilihan menu yang tersedia : " << endl;
		cout << "1. Tambah Komik" << endl;
        cout << "2. Kirim Komik ke Toko" << endl;
        cout << "3. Tampil Komik di Gudang" << endl;
        cout << "4. Cari Komik di Gudang" << endl;
        cout << "5. Hapus Komik di Gudang" << endl;
        cout << "6. Keluar" << endl << endl;
        cout << ">> Masukkan Pilihan : "; cin >> pilihan;

        cout << endl;
        switch (pilihan) {
            case 1: tambah(); getch(); break;
            case 2: kirim(); getch(); break;
            case 3: tampil(); getch(); break;
            case 4: cari(); getch(); break;
            case 5: hapus(); getch(); break;
            case 6:
                cout << "Terima Kasih Telah Menggunakan Program Ini..." << endl;
                getch(); break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
        }
        system("cls");	
    } while (pilihan != 5);
    return 0;
}