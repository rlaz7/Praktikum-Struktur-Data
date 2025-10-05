#include <iostream> 
using namespace std; 
 
int main() { 
    const int x = 10;
    char data[x] = {'A', 'E', 'D', 'B', 'A', 'B', 'C', 'A', 'D', 'B'}; 
    char nilai; 
    int r = 0; 

    cout << "Masukkan huruf yang ingin dicari(A-E) : "; 
    cin >> nilai; 
    nilai = toupper(nilai);

    for(int i = 0; i < x; i++){
        if (data[i] == nilai){
            r++;
        }
    }

    if (nilai > 0) { 
        cout << "Nilai " << nilai << " ditemukan sebanyak " << r << " kali." << endl; 
    } 
    else { 
        cout << "Nilai " << nilai << " tidak ada." << endl; 
    } 

    return 0; 
} 