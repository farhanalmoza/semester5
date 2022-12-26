#include<bits/stdc++.h>
#include <conio.h>
using namespace std;

// STRUCT KOMIK
struct komik {
    int kode_komik, tahun;
    char judul[50], penerbit[50], pengarang[50];
    struct komik *next;
};
struct komik* front = NULL;
struct komik* rear = NULL;
struct komik* temp;

// buat node AVL tree
class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

/* fungsi untuk membuat node baru
   dengan key yang diberikan */
Node* newNode(int key) {
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // node baru di tambahkan
					// di daun
	return(node);
}

// fungsi untuk mendapatkan tinggi node
int height(Node *N) {
	if (N == NULL)
		return 0;
	return N->height;
}

// fungsi untuk melakukan rotasi kanan
Node *rightRotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;

	// Lakukan rotasi
	x->right = y;
	y->left = T2;

	// Update tinggi
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// fungsi untuk melakukan rotasi kiri
Node *leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;

	// Lakukan rotasi
	y->left = x;
	x->right = T2;

	// Update tinggi
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// fungsi untuk mendapatkan balance factor
int getBalance(Node *N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// fungsi min value node
Node * minValueNode(Node* node) {
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// fungsi insert BST
Node* insertBST(Node* node, int key) {
	/* 1. normal BST insert */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insertBST(node->left, key);
	else if (key > node->key)
		node->right = insertBST(node->right, key);
	else // nilai key sama dengan node yang ada
		return node;

	/* 2. Update tinggi node */
	node->height = 1 + max(height(node->left),
						height(node->right));

    return node;
}

// START SHOW ALL
void tampil(int kode_komik) {
    int flag = 0;
    temp = front;

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
    }

    cout << endl;
}

// fungsi untuk melakukan preorder traversal
void preOrder(Node *root) {
	if(root != NULL)
	{
        // panggil fungsi tampil
        tampil(root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

// fungsi untuk melakukan inorder traversal
void inOrder(Node *root) {
    if(root != NULL) {
        inOrder(root->left);
        // panggil fungsi tampil
        tampil(root->key);
        inOrder(root->right);
    }
}

// fungsi untuk melakukan postorder traversal
void postOrder(Node *root) {
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        // panggil fungsi tampil
        tampil(root->key);
    }
}
// END SHOW ALL

// START DELETE
Node* deleteNode(Node* root, int kode_komik) {
    // STEP 1: NORMAL BST DELETE
    if (root == NULL)
        return root;

    // Jika kunci yang akan dihapus lebih kecil dari
    // root->key, maka akan berada di subtree kiri
    if (kode_komik < root->key)
        root->left = deleteNode(root->left, kode_komik);

    // Jika kunci yang akan dihapus lebih besar dari
    // root->key, maka akan berada di subtree kanan
    else if (kode_komik > root->key)
        root->right = deleteNode(root->right, kode_komik);

    // Jika kunci yang akan dihapus sama dengan root->key
    else {
        // node dengan satu anak atau tanpa anak
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;

            // Tidak ada anak
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else // Ada satu anak
                *root = *temp; // Copy isi dari anak
            free(temp);
        }
        else {
            // node dengan dua anak: dapatkan inorder successor
            // (nilai terkecil di subtree kanan)
            Node* temp = minValueNode(root->right);

            // Copy isi inorder successor ke node yang akan dihapus
            root->key = temp->key;

            // Hapus inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // Jika tree hanya memiliki satu node
    if (root == NULL)
        return root;

    // STEP 2: UPDATE TINGGI NODE
    root->height = 1 + max(height(root->left),
                        height(root->right));

    // STEP 3: GET BALANCE FACTOR
    int balance = getBalance(root);

    // Jika node tidak balance, ada 4 kasus

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
// END DELETE

void tambah(int kode_komik) {
    char judul[50];
    char penerbit[50];
    char pengarang[50];
    int tahun;
    
    cout << ">> Masukkan Judul Komik		: "; cin >> judul;
    cout << ">> Masukkan Penerbit Komik	: "; cin >> penerbit;
    cout << ">> Masukkan Pengarang Komik	: "; cin >> pengarang;
    cout << ">> Masukkan Tahun Terbit Komik	: "; cin >> tahun;

    if (rear == NULL) {
        rear = (struct komik *)malloc(sizeof(struct komik));
        rear->next = NULL;
        rear->kode_komik = kode_komik;
        strcpy(rear->judul, judul);
        strcpy(rear->penerbit, penerbit);
        strcpy(rear->pengarang, pengarang);
        rear->tahun = tahun;
        front = rear;
    } else {
        temp=(struct komik *)malloc(sizeof(struct komik));
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

// fungsi cari komik
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

int main() {
    int pilihan;
    
    cout << "===============================" << endl;
	cout << "=== Program Pendataan Komik ===" << endl; 
	cout << "===============================" << endl << endl;
	
	cout << "DISUSUN OLEH KELOMPOK 5 " << endl;
	cout << "Azka Avicenna Rasjid	[20081010115]" << endl;
	cout << "Farkhan			[20081010060]" << endl;
	cout << "Kuncoro Ariadi		[20081010096]" << endl << endl;

	Node *root = NULL;

    do {
        cout << "Pilihan menu yang tersedia : " << endl;
        cout << "1. Tambah Komik (BST)" << endl;
        cout << "2. Hapus Komik (AVL)" << endl;
        cout << "3. Cari Komik" << endl;
        cout << "4. Lihat Komik" << endl;
        cout << "5. Keluar" << endl << endl;
        cout << ">> Masukkan Pilihan : "; cin >> pilihan;

        cout << endl;
        switch (pilihan) {
            case 1: 
                // insert BST
                int kode_komik;
                cout << ">> Masukkan Kode Komik		: "; cin >> kode_komik;
                tambah(kode_komik);
                root = insertBST(root, kode_komik);
                break;
            case 2:
                // delete AVL
                int kode_komik_hapus;
                cout << "Masukkan kode komik yang akan dihapus: "; cin >> kode_komik_hapus;
                root = deleteNode(root, kode_komik_hapus);
                getch();
                break;
            case 3: cari(); getch(); break;
            case 4: 
                // lakukan pilihan traversal
                int pilihan_traversal;
                cout << "Pilihan traversal yang tersedia : " << endl;
                cout << "1. Preorder" << endl;
                cout << "2. Inorder" << endl;
                cout << "3. Postorder" << endl << endl;
                cout << ">> Masukkan Pilihan : "; cin >> pilihan_traversal;
                cout << endl;
                switch (pilihan_traversal) {
                    case 1:
                        cout << "Data komik yang ada di gudang: " << endl;
                        preOrder(root);
                        getch();
                        break;
                    case 2:
                        cout << "Data komik yang ada di gudang: " << endl;
                        inOrder(root);
                        getch();
                        break;
                    case 3:
                        cout << "Data komik yang ada di gudang: " << endl;
                        postOrder(root);
                        getch();
                        break;
                    default:
                        cout << "Pilihan tidak tersedia" << endl;
                }
                break;
            case 5: 
                cout << "Terima Kasih Telah Menggunakan Program Ini..." << endl;
                getch();
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
        }
        system("cls");	
    } while (pilihan != 5);
    
    return 0;
}