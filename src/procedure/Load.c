#include <stdio.h>
#include <stdlib.h>


void Load(const char* filename){
  FILE *file;
  char path[100];  
  int i = 0;
  int j = 0;
  const char *folder = "/save/";

  
  while (path[i] != '\0') {
    path[j++] = folder[i++];
  }
  i = 0;
  while (filename[i] != '\0') {
    path[j++] = filename[i++];
  }
  path[j] = '0';

 
  file = fopen(path, "r");
  if (file) {
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.");
    fclose(file);
  } else {
    printf("Save file tidak ditemukan. PURRMART gagal dijalankan.");
  }  
  return;
}

int main () {
  return 0;
}

