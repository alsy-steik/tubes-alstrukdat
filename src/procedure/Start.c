#include <stdio.h>
#include <stdlib.h>


void START(){
  
  char path[] = "/save/config.txt";

  file = fopen(path);
  printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.");
  fclose (file);
  return;
}
