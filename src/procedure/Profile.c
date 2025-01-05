#include <stdio.h>
#include "../adt/User/User.h"
#include "../adt/ArrayStat/ArrayStat.h"

extern ArrayStat user;         
extern int IndeksUser; 

void showProfile(){
    // Debug List Jaga2
    // int Counter;
    if (user.len == 0){
        printf("Belum ada pengguna yang terdaftar ᓀ‸ᓂ\n");
        return;
    }
    // End
    else {
        printf("=====================================\n");  
        printf("User %s's Details:\n", user.arr[IndeksUser].name);
        printf("  Saldo : %d\n", user.arr[IndeksUser].money);
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
