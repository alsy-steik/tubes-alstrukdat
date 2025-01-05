#include <stdio.h>
#include "../boolean.h"
#include "../adt/User/User.h"
#include "../adt/ArrayStat/ArrayStat.h"

extern ArrayStat user;         
extern int IndeksUser;    

void Logout() {
    // cek pengguna yang sedang login
    if (IndeksUser != -1) {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", 
               user.arr[IndeksUser].name);

        // reset indeks user yang login
        IndeksUser = -1; 
    } else {
        printf("Tidak ada pengguna yang sedang login.\n");
    }
}
