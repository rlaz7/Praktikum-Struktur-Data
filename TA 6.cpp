#include <iostream>
using namespace std;

const int SIZE = 10;

enum SlotState { EMPTY, OCCUPIED, DELETED };

struct Entry {
    int key;
    string value;
    SlotState state;
};

int hashFunction(int key) { return (key % SIZE + SIZE) % SIZE; }

void initTable(Entry table[]) {
    for (int i = 0; i < SIZE; ++i) {
        table[i].state = EMPTY;
    }
}

bool insert(Entry table[], int key, string value) {
    int idx = hashFunction(key);
    int firstDeleted = -1;

    for (int step = 0; step < SIZE; ++step) {
        int i = (idx + step) % SIZE;

        if (table[i].state == OCCUPIED) {
            if (table[i].state == OCCUPIED && table[i].key == key) {
            table[i].value = value;
        return true;
        }
        } else if (table[i].state == DELETED) {
            if (firstDeleted == -1) firstDeleted = i;
        } else { 
            if (firstDeleted != -1) i = firstDeleted; 
            table[i].key = key;
            table[i].value = value;
            table[i].state = OCCUPIED;
            return true;
        }
    }

    if (firstDeleted != -1) {
        table[firstDeleted].key = key;
        table[firstDeleted].value = value;
        table[firstDeleted].state = OCCUPIED;
        return true;
    }
    cout << "RAK SUDAH PENUH\n"; 
    return false;
}

Entry* search(Entry table[], int key) {
    int idx = hashFunction(key);

    for (int step = 0; step < SIZE; ++step) {
        int i = (idx + step) % SIZE;

        if (table[i].state == EMPTY) {
            return nullptr;
        }
        if (table[i].state == OCCUPIED && table[i].key == key) {
            return &table[i];
        }
    }
    return nullptr;
}

bool removeKey(Entry table[], int key) {
    Entry* e = search(table, key);
    if (!e) return false;
    e->state = DELETED;
    return true;
}

void display(Entry table[]) {
    cout << "\nIsi RAK Sepatu:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << i << ": ";
        if (table[i].state == EMPTY) cout << "EMPTY\n";
        else if (table[i].state == DELETED) cout << "DELETED\n";
        else cout << "(" << table[i].key << "," << table[i].value << ")\n";
    }
}

int main() {
    Entry table[SIZE];
    initTable(table);
    int q = 0;
    char h;
    string w;

    display(table);
    while (h != 'y' && h != 'Y'){
        cout << "Masukan Nomor Sepatu: ";
        cin >> q;
        cout << "Masukan Nama Sepatu: ";
        cin >> w;
        int j = 0;
        while (j < w.length()){
            w[j] = toupper (w[j]);
            j++;
        }
        insert (table, q, w);
        display (table);
        cout << "Apakah sudah selesai, jika sudah ketik 'y' untuk keluar: ";
        cin >> h;
    };
    cout << "Nomor Sepatu yang ingin di Ambil: ";
    cin >> q;
    Entry *hasil = search(table, q);
    if (hasil) {
        cout << "Ukuran "<< q << " Ditemukan dengan nama: " << hasil->value << endl;
        removeKey (table, q);
    }
    else{
        cout << "Ukuran " << q << " Tidak ditemukan";
    }
    display(table);
    cout << "Ukuran " << q << " sudah diambil" << endl;
    return 0;
}