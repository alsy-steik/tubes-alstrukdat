#include <stdio.h>
#include "../boolean.h"
#include "../adt/User/User.h"

extern ListUser USERS;         
extern int indeksUser;    

void Logout() {
    // cek pengguna yang sedang login
    if (indeksUser != -1) {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", 
               USERS.ElUser[indeksUser].name);

        // reset indeks user yang login
        indeksUser = -1; 
    } else {
        printf("Tidak ada pengguna yang sedang login.\n");
    }
}