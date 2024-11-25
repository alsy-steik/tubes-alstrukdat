#include <stdio.h>
#include <stdlib.h>


void remove_newline(char *str) {
  int i = 0;
  while (str[i] != '\0') {
      i++;
  }
  if (i > 0 && str[i - 1] == '\n') {
      str[i - 1] = '\0';
  }
}



void START(){
  FILE *file;
  int N;
  int M;
  
  
  char path[] = "/save/config.txt";

  file = fopen(path);
  
  fscanf(file, "%d", &N);

  int i;
  for (i = 0; i < N; i++) {
      fscanf(file, "%d", &barang[i].harga);
      fgets(barang[i].nama, sizeof(barang[i].nama), file);
      remove_newline(barang[i].nama);
  }


  fscanf(file, "%d", &M);

  for (i = 0; i < M; i++) {
    fscanf(file, "%d", &pengguna[i].uang);
    fgets(pengguna[i].nama, sizeof(pengguna[i].nama), file);
    fgets(pengguna[i].password, sizeof(pengguna[i].password), file);
    remove_newline(pengguna[i].nama);     
    remove_newline(pengguna[i].password); 
  }


  fclose (file);
  printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.");
  return;
}



int main() {
  Barang barang[MAX_BARANG];
  User pengguna[MAX_PENGGUNA];

  START();
  return 0;
}
