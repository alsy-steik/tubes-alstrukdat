#include <stdio.h>
#include "../boolean.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/User/User.h"

ListUser USERS;
int IndeksUser;

// Function ubah tipe kata ke string
void KataKeString(Kata kata, char *String){
    int Indeks;
    for (Indeks = 0; Indeks < kata.length; Indeks++){
        String[Indeks] = kata.buffer[Indeks];
    }
    String[kata.length] = '\0';
}

// Function buat ngebanding string
boolean BandingString(const char *String1, const char *String2){
    int Indeks;
    while (String1[Indeks] != '\0' && String2[Indeks] != '\0'){
        if (String1[Indeks] != String2[Indeks]){
            return false;
        }
        Indeks++;
    }

    return (String1[Indeks] == '\0' && String2[Indeks] == '\0');
}

// void CopyString(char *Hasil, const char *Input, int Panjang){
//     int Indeks;
//     for (Indeks = 0; Indeks < Panjang; Indeks++){
//         Hasil[Indeks] = Input[Indeks];
//     }
//     Hasil[Panjang] = '\0';
// }

// Function cek username ada di listuser
int UsernameAda(const char *Input){
    int Indeks;
    for (Indeks = 0; Indeks < USERS.lengthEff; Indeks++){
        if (BandingString(USERS.ElUser[Indeks].name, Input)){
            return (Indeks);
        }
    }
    return (-1);
}

// Function login
boolean Login(){
    char Username[MAX_USER_NAME];
    char Password[MAX_USER_PASS];
    int CurrentindeksUser;
    int Counter;

    if (IndeksUser != -1){
        printf("Anda masil terlogin, logout dulu bosqu\n");
        return;
    }

    printf("== Login ==\n");
    printf("Masukkan Username: \n");
    startKata(NULL);
    KataKeString(currentKata, Username);

    for (Counter = 0; Counter < USERS.lengthEff; Counter++){
        if (UsernameAda(Username) == -1){
            printf("Username tidak ditemukan\n");
        }
        else {
            CurrentindeksUser = UsernameAda(Username);
        }
    }

    printf("Masukkan Password: \n");
    startKata(NULL);
    KataKeString(currentKata, Password);

    if (BandingString(Password, USERS.ElUser[CurrentindeksUser].password)){
        IndeksUser = CurrentindeksUser;
        *session = USERS.ElUser[CurrentindeksUser];
        printf("Login Berhasil, Selamat datang kembali %s\n", Username);
        return true;
    }
    

    printf("Password yang anda masukkan salah\n ");
    return false;
}

// Function register
boolean Register(){
    char Username[MAX_USER_NAME];
    char Password[MAX_USER_PASS];
    int Money = 1000;
    int Counter;
    User userBaru;

    printf("== Register ==\n");
    printf("Masukkan Username: \n");
    startKata(NULL);
    KataKeString(currentKata, Username);

    for (Counter = 0; Counter < USERS.lengthEff; Counter++){
        if (UsernameAda(Username) != -1){
            printf("Username sudah terdaftar, buat username lain\n ");
            return false;
        }
    }

    printf("Masukkan Password: \n");
    startKata(NULL);
    KataKeString(currentKata, Password);

    userBaru = createUser(Username, Password, Money);
    addUser(&USERS, userBaru);
    printf("Registrasi Selesai!\n");
    return true;
}
