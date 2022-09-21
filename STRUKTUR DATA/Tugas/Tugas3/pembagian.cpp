#include <iostream>
using namespace std;
int bagi(int a, int b)
{
    if (a < b)
        return 0;
    else
        return 1 + bagi(a-b, b);
}

int main()
{
    int a, b;
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;
    cout << "Hasil pembagian: " << bagi(a, b) << endl;
    return 0;
}