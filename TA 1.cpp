#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 5;
const int COLS = 8;
const double TICKET_PRICE = 35000.0;

void initializeSeats(char seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = 'O';
        }
    }
}

void displaySeats(const char seats[ROWS][COLS]) {
    cout << "\n       ======= LAYAR BIOSKOP =======\n\n";
    cout << "         ";
    for (int j = 0; j < COLS; j++) {
        cout << setw(3) << j + 1;
    }
    cout << "\n    ----------------------------------\n";

    for (int i = 0; i < ROWS; i++) {
        cout << "Baris " << (char)('A' + i) << " |";
        for (int j = 0; j < COLS; j++) {
            cout << setw(3) << seats[i][j];
        }
        cout << " |\n";
    }
    cout << "    ----------------------------------\n";
    cout << "Keterangan: [O] = Tersedia, [X] = Terisi\n";
}

bool bookTicket(char seats[ROWS][COLS]) {
    char rowChar;
    int col;

    cout << "\n--- Pilih Kursi ---\n";
    cout << "Masukkan baris (A-" << (char)('A' + ROWS - 1) << "): ";
    cin >> rowChar;
    rowChar = toupper(rowChar);

    cout << "Masukkan nomor kursi (1-" << COLS << "): ";
    cin >> col;

    int rowIndex = rowChar - 'A';
    int colIndex = col - 1;

    if (rowIndex < 0 || rowIndex >= ROWS || colIndex < 0 || colIndex >= COLS) {
        cout << "\n[ERROR] Nomor kursi tidak valid. Silakan coba lagi.\n";
        return false;
    }

    if (seats[rowIndex][colIndex] == 'O') {
        seats[rowIndex][colIndex] = 'X';
        cout << "\n[OK] Selamat! Kursi " << rowChar << col << " berhasil dipesan.\n";
        return true;
    } else {
        cout << "\n[GAGAL] Maaf, kursi " << rowChar << col << " sudah terisi. Silakan pilih kursi lain.\n";
        return false;
}
}
int main() {
    char seats[ROWS][COLS];
    int bookedTickets = 0;
    int choice;

    initializeSeats(seats);

    do {
        cout << "\n===== SISTEM PEMESANAN TIKET BIOSKOP =====\n";
        cout << "1. Tampilkan Denah Kursi\n";
        cout << "2. Pesan Tiket\n";
        cout << "3. Lihat Total Pesanan\n";
        cout << "4. Keluar\n";
        cout << "==========================================\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                if (bookTicket(seats)) {
                    bookedTickets++;
                }
                break;
            case 3:
                cout << "\n--- Total Pesanan Anda ---\n";
                cout << "Jumlah Tiket Dipesan: " << bookedTickets << "\n";
                cout << "Total Harga         : Rp " << (bookedTickets * TICKET_PRICE) << "\n";
                break;
            case 4:
                cout << "\nTerima kasih telah menggunakan sistem kami!\n";
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan masukkan angka 1-4.\n";
        }

    cin.clear();
    cin.ignore(10000, '\n');

    } while (choice != 4);

    return 0;
}