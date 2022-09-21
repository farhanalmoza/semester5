#include <iostream>
using namespace std;
int kali(int a, int b)
{
    if (b == 1)
        return a;
    else
        return a + kali(a, b-1);
}

int main()
{
    int a, b;
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;
    cout << "Hasil perkalian: " << kali(a, b) << endl;
    return 0;
}