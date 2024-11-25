#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int money = 10000;

void W0RDL3() {
    // Biaya Main
    int biayaW0RDL3 = 500;
    if (money < biayaW0RDL3) {
        printf("Uang anda tidak cukupp!");
        return;
    } else {
        money -= biayaW0RDL3;
    }
    
    int panjangkata = 5;
    int prize = 1500;
    int chances = 6;
    
    char words[8][6] = {"TUGAS", "SUSAH", "TIDAK", "JELAS", "MABOK", "CUKUP", "LELAH", "KACAU"};
    char answer[6];
    
    //random answer
    srand(time(NULL));
    int randomIndex = rand() % 8;
    for (int i = 0; i < 6; i++) {
        answer[i] = words[randomIndex][i];
    }

    
    printf("\nWELCOME TO W0RDL3, YOU HAVE 6 CHANCES TO ANSWER BEFORE YOU LOSE!\n");
    
  
    // deklarasi matriks
    char guess[2][chances][panjangkata];
    for (int i = 0; i < chances; i++) {
        for (int j = 0; j < panjangkata; j++) {
            guess[0][i][j] = '_';
            guess[1][i][j] = ' ';
            for (int k = 0; k < 2; k++) {
                printf("%c", guess[k][i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    

    //loop menjawab
    for (int try = 0; try < chances; try++) {
        char tebak[6];
        
        
        int tebakanValid = 0;
        while (tebakanValid == 0) {
            printf("Masukan kata tebakan Anda: ");
            scanf("%s", tebak);
            
            tebakanValid = 1;
            for (int i = 0; i < panjangkata; i++) {
                if (tebak[i] == '\0') {
                    tebakanValid = 0; // Kurang dari 5 huruf
                    break;
                }
            }
            if (tebak[panjangkata] != '\0') {
                tebakanValid = 0; // Lebih dari 5 huruf
            }
        }
        
        
        printf("Hasil:\n");
        
        
        for (int i = 0; i < panjangkata; i++) {
            guess[0][try][i] = tebak[i];
            //anggep salah semua, tambah %
            guess[1][try][i] ='%';
            //kalo ada hurufnya tambah *
            for (int j = 0; j < panjangkata; j++) {
                if (tebak[i] == answer[j]) {
                    guess[1][try][i] = '*';
                }
            }
            //kalo hurufnya bener tempat hilangin
            if (tebak[i] == answer[i]) {
                guess[1][try][i] =' ';
            }
        }
        
        // print matriks
        for (int i = 0; i < chances; i++) {
            for (int j = 0; j < panjangkata; j++) {
                for (int k = 0; k < 2; k++) {
                    printf("%c", guess[k][i][j]);
                }
                printf (" ");
            }
            printf("\n");
        }
        printf("\n");
        
        // jika menang
        int tebakBener = 1;
        for (int i = 0; i < panjangkata; i ++) {
            if (guess[1][try][i] != ' ') {
                tebakBener = 0;
            }
        }
        if (tebakBener == 1) {
            printf("Selamat, Anda menang!\n");
            printf("+%d rupiah telah ditambahkan ke akun Anda.\n", prize);
            money += prize;
            return;
        }
    }
    
    
    // jika kesempatan habis = kalah
    printf("Boo! Anda kalah.");
}
 
// int main() {
//     printf("Uang anda ");
//     printf("%d\n", money);
//     W0RDL3();
//     printf("\nUang anda ");
//     printf("%d\n", money);
//     return 0;
// }
