#include "User.h"
#include "../../util/util.h"

void setName(User* user, const char* name) {
    int i = 0;
    strcpyHomemade(user->name, name)
    // while(name[i] != '\0') {
    //     user->name[i] = name[i];
    //     ++i;
    // }
    // user->name[i] = '\0';
}

void setPassword(User* user, const char* password) {
    int i = 0;
    strcpyHomemade(user->password, password);
    // while(password[i] != '\0') {
    //     user->password[i] = password[i];
    //     ++i;
    // }
    // user->password[i] = '\0';
}

// set be lgsung njir sbnernya mah
void setMoney(User* user, int money) {
    user->money = money;
}

User createUser(const char* name, const char* password, int money) {
    User new_user;
    setName(&new_user, name);
    setPassword(&new_user, password);
    setMoney(&new_user, money);
    return new_user;
}

void addUser(ListUser *LUser, User u){
    if ((*LUser).lengthEff < MAX_USERS){
        (*LUser).ElUser[(*LUser).lengthEff] = u;
        (*LUser).lengthEff++;
    }
}


