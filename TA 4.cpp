#include <iostream>
using namespace std;

const int MAX = 100;
char nama[MAX];
int topIdx = -1;

bool isEmpty() {
    return topIdx == -1;
}
bool isFull() {
    return topIdx == MAX - 1;
}
void push(char n) {
    if (isFull()) {
        cout << "Tumpukan penuh! Tidak bisa menambah huruf.\n";
        return;
    }
    nama[++topIdx] = n;
    cout << "Huruf '" << n << "' berhasil ditambahkan.\n";
}
void pop() {
    if (isEmpty()) {
        cout << "Tumpukan kosong! Tidak ada Huruf.\n";
        return;
    }
    cout << "Huruf '" << nama[topIdx--] << "' diambil dari tumpukan.\n";
}
void peek() {
    if (isEmpty()) {
        cout << "Tumpukan kosong.\n";
        return;
    }
    cout << "Huruf teratas: '" << nama[topIdx] << "'\n";
}
void display() {
    if (isEmpty()) {
        cout << "Tumpukan kosong.\n";
        return;
    }
    cout << "Huruf (kiri ke kanan): ";
    for (int i = topIdx; i >= 0; --i) {
        cout << nama[i] << " ";
    }
    cout << endl;
}

int main() {
    int pilih;
    char nama;
    do {
        cout << "\n=== SIMULASI NAMA TERBALIK ===\n";
        cout << "1. Tambah Huruf\n";
        cout << "2. Keluarkan Huruf\n";
        cout << "3. Lihat Huruf terdepan\n";
        cout << "4. Tampilkan semua huruf\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                cout << "Masukkan Huruf: ";
                cin >> nama;
                nama = toupper(nama);
                push(nama);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);
    return 0;
}