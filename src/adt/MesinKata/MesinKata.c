#include "MesinKata.h"
#include "../Stack/stack.h"
#include "../SetMap/setmap.h"
#include "../LinkedList/doublyLinkedList.h"
#include "../../util/util.h"


void loadRiwayatPembelianUser(User* user);

boolean endKata;
boolean isStdin;
Kata currentKata;

void ignoreBlank() {
    while(cc == BLANK) {
        // puts("bjirnigga");
        adv();
    }
}

void startKata(const char* path) {
    isStdin = path == NULL;
    start(path);
    ignoreBlank();
    if(cc == MARK) {
        endKata = true;
    } else {
        endKata = false;
        salinKata();
    }
}

void startKataMajemuk(const char* path) {
    isStdin = path == NULL;
    start(path);

    ignoreBlank();
    if(cc == EOF) {
        endKata = true;
    } else {
        endKata = false;
        salinKataMajemuk();
    }
}

void advKata() {
    ignoreBlank();
    if((!isStdin && cc == EOF) || (isStdin && cc == EOL)) {
        endKata = true;
    } else {
        endKata = false;
        salinKata();
    }
}

void advKataMajemuk() {
    ignoreBlank();
    if ((!isStdin && cc == EOF) || (isStdin && cc == EOL))
    {
        endKata = true;
    }
    else
    {
        endKata = false;
        salinKataMajemuk();
    }
}



void salinKata() {
    int i = 0;
    while((cc != EOL) && (cc != BLANK)) {
        currentKata.buffer[i] = cc;
        adv();
        ++i;
    }


    // incase we read from a file, reset the current character, so we could read from the next line
    if(cc == EOL && !isStdin) cc = BLANK;

    currentKata.buffer[i] = '\0';
    currentKata.length = i;
}

void salinKataMajemuk() {
    int i = 0;
    while((cc != EOL)) {
        currentKata.buffer[i] = cc;
        adv();
        ++i;
    }
    if(!isStdin) cc = BLANK;
    currentKata.buffer[i] = '\0';
    currentKata.length = i;
}

int  getNum() {
    startKata(NULL);
    return atoi(currentKata.buffer);
}

boolean saveFile(const char *filename, ArrayStat *user, ArrayDin *barang)
{
    int i = 0;
    while(filename[i] != '\0') {
        if (filename[i] == '\\' || filename[i] == '/') return false;
        ++i;
    }

    char full_path[100];
    sprintf(full_path, "config/%s", filename);

    FILE *fptr = fopen(full_path, "w");

    fprintf(fptr, "%d\n", barang->len);
    // printf("%d\n", barang->len);
    for (int i = 0; i < barang->len; ++i)
    {
        Barang bjir = (barang->arr)[i];
        fprintf(fptr, "%d %s\n", bjir.price, bjir.name);
        // printf("%d %s\n", bjir.price, bjir.name);
    }

    fprintf(fptr, "%d\n", user->len);
    // printf("%d\n", user->len);
    for (int i = 0; i < user->len; ++i)
    {
        User bjir = (user->arr)[i];
        fprintf(fptr, "%d %s %s\n", bjir.money, bjir.name, bjir.password);
        // printf("%d %s %s\n", bjir.money, bjir.name, bjir.password);

        fprintf(fptr, "%d\n", bjir.riwayat_pembelian.len);
        // printf("%d\n", bjir.riwayat_pembelian.len);
        while(bjir.riwayat_pembelian.len) {
            StackElType curr = top(bjir.riwayat_pembelian);
            fprintf(fptr, "%d %s\n", curr.harga_total, curr.nama_barang);
            // printf("%d| %d %s\n", bjir.riwayat_pembelian.len, curr.harga_total, curr.nama_barang);
            pop(&bjir.riwayat_pembelian);
        }

        fprintf(fptr, "%d\n",bjir.wishlist.len);
        // printf("%d\n", bjir.wishlist.len);
        while (bjir.wishlist.len)
        {
            fprintf(fptr, "%s\n", bjir.wishlist.head->data);
            // printf("%s\n", bjir.wishlist.head->data);
            LinkedListDeleteBeginning(&(bjir.wishlist));
        }
    }

    fclose(fptr);
    fptr = fopen("config/default/default.txt", "w");
    fprintf(fptr, "config/%s\n", filename);
    fclose(fptr);
    return true;
}

void loadBarang(ArrayDin *barang) {
    // printf("Retrieving barang length...\n");
    int n = atoi(currentKata.buffer);
    // printf("Barang length retrieved : %d\n", n);
    while (n--)
    {
        Barang item;
        // printf("Adding barang #%d...\n", n+1);
        // printf("Retrieving barang #%d's price..\n", n+1);
        advKata();
        setBarangPrice(&item, atoi(currentKata.buffer));
        // printf("barang #%d's price retrieved: %s\n",n+1 ,currentKata.buffer);

        // printf("Retrieving barang #%d's name..\n", n+1);
        advKataMajemuk();
        // printf("barang #%d's name retrieved: %s\n", n+1,currentKata.buffer);
        setBarangName(&item, currentKata.buffer);

        ArrayDinInsertEnd(barang, item);
        // printf("Barang #%d added successfully:D\n");
    }
}

void loadWishlist(User* u) {

    createEmptyLinkedList(&(u->wishlist));

    advKata();
    int n = atoi(currentKata.buffer);
    while (n--)
    {
        advKataMajemuk();
        LinkedListInsertEnd(&(u->wishlist), currentKata.buffer);
    }
    
}

void loadUserData(ArrayStat *user_list) {
    User u;
    
    MapCreateEmpty(&(u.keranjang));

    advKata();
    setMoney(&u,atoi(currentKata.buffer));

    advKata();
    setName(&u, currentKata.buffer);

    advKata();
    setPassword(&u, currentKata.buffer);

    loadRiwayatPembelianUser(&u);
    loadWishlist(&u);

    insertEnd(user_list, u);
}

void loadRiwayatPembelianUser(User* user) {

    StackInitEmpty(&(user->riwayat_pembelian));

    advKata();
    int n = atoi(currentKata.buffer);
    while(n--) {
        advKata();
        int price = atoi(currentKata.buffer);
        advKataMajemuk();
        pushNT(&(user->riwayat_pembelian), currentKata.buffer, price);
    }
}

void loadUsers(ArrayStat *user_list) {
    advKata();
    int n = atoi(currentKata.buffer);
    while (n--) loadUserData(user_list);
}

boolean validateFilename(const char *filename) {
    int i = 0;
    while (filename[i] != '\0')
    {
        if(filename[i] == '\\' || filename[i] == '/') return false;
        ++i;
    }
    return true;
}

boolean Load(const char *filename, ArrayStat *user, ArrayDin *barang)
{
    
    if(filename == NULL) {
        startKata("config/default/default.txt");
        close();
        // printf(currentKata.buffer);
        startKata(currentKata.buffer);
    } else {
        char full_path[100]; 

        // full path construction
        if(!validateFilename(filename)) return false;

        sprintf(full_path, "config/%s", filename);

        // open the stream
        // printf("Opening config file: %s...\n", filename);
        startKata(full_path);
    }
    // printf("%s opened successfully:D\n", filename);
    // printf("Loading barang...\n");
    loadBarang(barang);
    // printf("Barang loaded successfully:D\n");
    // printf("Loading users...\n");
    loadUsers(user);
    // printf("User loaded successfully:D\n");
    // printf("completed.\n");
    close();
    // return false;
    return true;
}

void PrintKata(Kata kata){
    for (int i = 0; i<kata.length; i++){
        printf("%s\n", kata.buffer[i]);
    }
}

// int main() {
//     ArrayDin barang;
//     MakeEmptyArrayDin(&barang);

//     ArrayStat user;
//     createEmpty(&user);

//     Load("sample.txt", &user, &barang);

//     saveFile("kucing.txt", &user, &barang);
//     // ArrayDin barang;
//     // MakeEmptyArrayDin(&barang);
//     // ArrayStat user;
//     // createEmpty(&user);
//     // puts("\n========================BARANG========================");

//     // for(int i = 0; i < barang.len; ++i) {
//     //     printf("{name: %s, price: %d}\n", barang.arr[i].name, barang.arr[i].price);
//     // }

//     // puts("\n=========================USER=========================");
//     // for(int i = 0; i < user.len; ++i) {
//     //     printf("User#%i:\n", i);
//     //     User u = user.arr[i];
//     //     printf("username: %s\n", u.name);
//     //     printf("password: %s\n", u.password);
//     //     printf("money: %d\n", u.money);
//     //     puts("riwayat pembelian: ");
//     //     Stack *temp = u.riwayat_pembelian;
//     //     while(temp != NULL) {
//     //         printf("- [total: %d, nama_barang: %s]\n",temp->data.harga_total, temp->data.nama_barang);
//     //         temp = temp->link;
//     //     }
//     //     puts("wishlist: ");
//     //     DoublyLinkedListNode *manig = u.wishlist;
//     //     while (manig != NULL)
//     //     {
//     //         printf("- %s\n", manig->data);
//     //         manig = manig->next;
//     //     }
        
//     //     putchar('\n');

//     // }
//     // ArrayDin barang;
//     // MakeEmptyArrayDin(&barang);

//     // startKata("sample.txt");
//     // int n = atoi(currentKata.buffer);

//     // printf("%d\n", n);
//     // while(n--) {
//     //     advKata();
//     //     int quantity = atoi(currentKata.buffer);
//     //     advKataMajemuk();
//     //     printf("%d %s\n", quantity, currentKata.buffer);
//     // }

//     // advKata();
//     // n = atoi(currentKata.buffer);
//     // printf("%d\n", n);
//     // while(n--) {
//     //     advKata();
//     //     int money = atoi(currentKata.buffer);

//     //     advKata();
//     //     char uname[100];
//     //     strcpyHomemade(uname, currentKata.buffer);

//     //     advKata();
//     //     char password[100];
//     //     strcpyHomemade(password, currentKata.buffer);

//     //     printf("%d %s %s\n", money, uname, password);
        
//     //     advKata();
//     //     int history_count = atoi(currentKata.buffer);
//     //     printf("%d\n", history_count);
//     //     while(history_count--) {
//     //         advKata();
//     //         int price = atoi(currentKata.buffer);
//     //         advKataMajemuk();
//     //         printf("%d %s\n", price, currentKata.buffer);
//     //     }

//     //     advKata();
//     //     int wishlist_count = atoi(currentKata.buffer);
//     //     printf("%d\n", wishlist_count);
//     //     while(wishlist_count--) {
//     //         advKataMajemuk();
//     //         printf("%s\n", currentKata.buffer);
//     //     }
//     // }
//     // startKata(NULL);
//     // while(!endKata) {
//     //     for (int i = 0; i < currentKata.length; i++)
//     //     {
//     //         // puts("a");
//     //         printf("%c", currentKata.buffer[i]);
//     //         // puts("a");
//     //     }
//     //     printf("\n");
//     //     advKata();
//     // }
// }
