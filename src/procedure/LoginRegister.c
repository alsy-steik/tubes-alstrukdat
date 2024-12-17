#include <stdio.h>
#include "../boolean.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/User/User.h"

ListUser USERS;
int IndeksUser;


// Function cek username ada di listuser
int UsernameAda(ListUser *USERS, const char *input){
    int Counter;
    for (Counter = 0; Counter < (*USERS).lengthEff; Counter++){
        if (is_same_string((*USERS).ElUser[Counter].name, input)){
            return true;
        }
    }
    return false;
}

// Funtion cek password (sama kek is_same_string() tapi ini case sensitive)
boolean is_same_string_password(const char str1[], const char str2[]){
    int i;
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

// Function login
void Login(){
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
    for (int Counter = 0; Counter < currentKata.length; Counter++){
        Username[Counter] = currentKata.buffer[Counter];
    }
    Username[currentKata.length] = '\0';

    if (!UsernameAda(&USERS, Username)){
        printf("Username tidak ditemukan\n ");
        return;
    }

    for (Counter = 0; Counter < USERS.lengthEff; Counter++){
        if (is_same_string(USERS.ElUser[Counter].name, Username)){
            CurrentindeksUser = Counter;
        }
    }

    printf("Masukkan Password: ");
    startKata(NULL);

    for (int Counter = 0; Counter < currentKata.length; Counter++){
            Password[Counter] = currentKata.buffer[Counter];
        }
    Password[currentKata.length] = '\0';

    if (is_same_string_password(USERS.ElUser[CurrentindeksUser].password,Password)){
        IndeksUser = CurrentindeksUser;
        printf("Login berhasil, Selamat Datang Kembali, %s\n", Username);
        return;
        
    }
    else {
        printf("Password salah\n");
        return;
    }

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

    for (int Counter = 0; Counter < currentKata.length; Counter++){
        Username[Counter] = currentKata.buffer[Counter];
    }
    Username[currentKata.length] = '\0';

    if (UsernameAda(&USERS, currentKata.buffer)){
        printf("Username sudah terdaftar, buat username lain\n ");
        return;
    }

    printf("Masukkan Password: ");
    startKata(NULL);
    while (currentKata.length == 0){
        printf("Password gaboleh kosong >:(\n ");
        printf("Masukkan Password: ");
        startKata(NULL);
    }

    for (int Counter = 0; Counter < currentKata.length; Counter++){
            Password[Counter] = currentKata.buffer[Counter];
        }
    Password[currentKata.length] = '\0';

    userBaru = createUser(Username, Password, Money);
    addUser(&USERS, userBaru);

    printf("Registrasi berhasil dan Username didaftarkan ke sistem!\n");
}
