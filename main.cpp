#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> kumpulanNama ={
                            "hansdika", "robih", "nabil", "kemal", "ale",
                            "beni", "tegar", "nafal", "faita", "rizqi",
                            "sultan", "hasbi", "fathur", "noval", "reza",
                            "faizun", "yudha", "michael", "asyraf", "harza",
                            "farid", "rizal", "faishal", "syafiq", "jeje",
                            "andra", "fauzan", "ali", "yadhit", "doni"
                            };
const int nyawa= 6;
bool mainLagi = true;
char cekUlang = '-';
int salah;
string namaRahasia;

string namaRandom() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomIndex = rand() % kumpulanNama.size();
    return kumpulanNama[randomIndex];
}

bool tertebak(const string& nama, const string& tebakan) {
    return nama == tebakan;
}

void displayNama(const string& tebakan) {
    cout << endl << "Nama : ";
    for (char huruf : tebakan) {
        cout << huruf << " ";
    }
    cout << endl;
}

void perulangan() {
    while (cekUlang != 'y' && cekUlang != 't') {
        cout << "Apakah kamu ingin main lagi ?  (y/t)" << endl;
        cin >> cekUlang;
        if (cekUlang == 'y') {
            mainLagi = true;
        } else if (cekUlang == 't'){
            mainLagi = false;
        }else{
            cout << "Input 'y' untuk mengulang permainan atau 't' untuk keluar dari permainan.";
        }
    }
}

void kalimatTemplate(string kalimat){
    if(kalimat == "welcome"){
        system("CLS");
        cout << endl;
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
        cout << "| Selamat datang di tebak nama GT B 11 !!! (Hangman Game) |" << endl;
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    }else if (kalimat == "tebak"){
        cout << "Tebak satu huruf : ";
    }else if (kalimat == "salah"){
        cout << "Tebakan salah! Nyawa tersisa: " << nyawa - salah << endl;
    }else if (kalimat == "menang"){
        cout << "Selamat! Kamu berhasil menebak nama: " << namaRahasia << endl << endl;
    }else if (kalimat == "kalah"){
        cout << "Ah payah, kamu kehabisan nyawa. Nama rahasia adalah: " << namaRahasia << endl << endl;
    }else if (kalimat == "goodbye"){
        system("CLS");
        cout << endl;
        cout << "Terimakasih sudah bermain! GT B itu 'B' nya berarti Bahagia loh!" << endl;
    }
}

int main() {

    while(mainLagi){
        //inisialisasi awal game
        namaRahasia = namaRandom();
        string papanSoal(namaRahasia.length(), '_');
        salah = 0;
        cekUlang = '-';

        kalimatTemplate("welcome");

        while (salah < nyawa) {
            //perulangan permainan
            displayNama(papanSoal);

            char tebak;
            kalimatTemplate("tebak");
            cin >> tebak;

            bool ketemu = false;
            for (int i = 0; i < namaRahasia.length(); ++i) {
                if (namaRahasia[i] == tebak) {
                    papanSoal[i] = tebak;
                    ketemu = true;
                }
            }

            if (!ketemu) {
                ++salah;
                kalimatTemplate("salah");
            }

            if (tertebak(namaRahasia, papanSoal)) {
                displayNama(papanSoal);
                kalimatTemplate("menang");
                break;
            }
        }

        if (salah == nyawa) {
            kalimatTemplate("kalah");
        }

        perulangan();
    }

    kalimatTemplate("goodbye");

    return 0;
}
