#include <stdio.h>
#include "../boolean.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/ArrayStat/ArrayStat.h"
#include "../adt/User/User.h"
#include "../util/util.h"

extern ArrayStat user;
extern int IndeksUser;


// Function cek username ada di listuser
int UsernameAda(ArrayStat USERS, const char *input){
    int Counter;
    for (Counter = 0; Counter < USERS.len; Counter++){
        if (is_same_string(USERS.arr[Counter].name, input)){
            return Counter;
        }
    }
    return -1;
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
boolean Login(){
    char Username[MAX_USER_NAME];
    char Password[MAX_USER_PASS];
    int CurrentindeksUser;
    int Counter;

    if (IndeksUser != -1){
        printf("Anda masil terlogin, logout dulu bosqu\n");
        return false;
    }

    printf("== Login ==\n");
    printf("Masukkan Username: \n");
    startKata(NULL);
    for (int Counter = 0; Counter < currentKata.length; Counter++){
        Username[Counter] = currentKata.buffer[Counter];
    }
    Username[currentKata.length] = '\0';

    int index = UsernameAda(user, Username);
    if (index == -1){
        printf("Username tidak ditemukan\n");
        return false;
    }

    for (Counter = 0; Counter < user.len; Counter++){
        if (is_same_string(user.arr[Counter].name, Username)){
            CurrentindeksUser = Counter;
        }
    }

    printf("Masukkan Password: ");
    startKata(NULL);

    for (int Counter = 0; Counter < currentKata.length; Counter++){
            Password[Counter] = currentKata.buffer[Counter];
        }
    Password[currentKata.length] = '\0';

    if (is_same_string_password(user.arr[CurrentindeksUser].password,Password)){
        IndeksUser = CurrentindeksUser;
        printf("Login berhasil, Selamat Datang Kembali, %s\n", Username);
        return true;
        
    }
    else {
        printf("Password salah\n");
        return false;
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

    if (UsernameAda(user, currentKata.buffer) != -1){
        printf("Username sudah terdaftar, buat username lain\n");
        return false;
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
    insertEnd(&user, userBaru);

    printf("Registrasi berhasil dan Username didaftarkan ke sistem!\n");
    return true;
}
