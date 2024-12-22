#include <stdio.h>
#include "../adt/User/User.h"

extern ListUser USERS;         
extern int indeksUser; 

void showProfile(){
    // Debug List Jaga2
    // int Counter;
    if (USERS.lengthEff == 0){
        printf("Belum ada pengguna yang terdaftar ᓀ‸ᓂ\n");
        return;
    }
    // End
    else {
        printf("=====================================\n");  
        printf("User %s's Details:\n", USERS.ElUser[indeksUser].name);
        printf("  Saldo : %d\n", USERS.ElUser[indeksUser].money);
        printf("=====================================\n");
        return;
    }
}

//debug asy
// int main(){
//     User user1 = createUser("Atma","wwww",1000);
//     addUser(&USERS,user1);
//     showProfile();
//     return 0;
// }