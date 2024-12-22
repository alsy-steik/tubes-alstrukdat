# PURRMART
PURRMART adalah aplikasi berbasis Command-Line Interface (CLI) yang dirancang untuk mensimulasikan sistem e-commerce sederhana dan interaktif. Aplikasi ini bertujuan memberikan pengalaman edukatif dan menyenangkan dengan memungkinkan pengguna untuk memahami alur proses e-commerce melalui berbagai fitur seperti pengelolaan barang, transaksi belanja, dan gamifikasi. Aplikasi ini dirancang modular dengan penggunaan struktur data dan algoritma untuk kebutuhan simulasi e-commerce berbasis CLI.

## Kelompok 07 K1 Algoritma dan Struktur Data STI
* Nabilah Amanda Putri
18221021
* Muhammad Rifky Fachrizain
18221027
* Ali Syauqie
18223045
* Stanislaus Ardy Bramantyo
18223057
* Dhafin Faidhulhaq
18223103

## Fitur
- START: Memulai sesi baru.
- LOAD: Memuat sesi dari file konfigurasi.
- REGISTER: Mendaftar akun baru.
- LOGIN: Masuk ke akun dan memulai sesi.
- WORK: Melakukan pekerjaan.
- WORK CHALLENGE: Mengerjakan tantangan kerja.
- STORE LIST: Melihat daftar barang di toko.
- STORE REQUEST: Meminta penambahan barang di toko.
- STORE SUPPLY: Menambahkan barang dari permintaan.
- STORE REMOVE: Menghapus barang di toko.
- PROFILE: Melihat profil pengguna (hanya saat login).
- CART ADD <nama> <n>: Menambahkan barang ke keranjang belanja.
- CART REMOVE <nama> <n>: Mengurangi barang dari keranjang belanja.
- CART SHOW: Melihat isi keranjang belanja.
- CART PAY: Melakukan pembayaran barang dalam keranjang.
- HISTORY <n>: Melihat riwayat pembelian.
- WISHLIST ADD: Menambahkan barang ke wishlist.
- WISHLIST SWAP <i> <j>: Menukar posisi barang di wishlist.
- WISHLIST REMOVE <i>: Menghapus barang di wishlist berdasarkan posisi.
- WISHLIST REMOVE: Menghapus barang di wishlist berdasarkan nama.
- WISHLIST CLEAR: Mengosongkan seluruh wishlist.
- WISHLIST SHOW: Melihat daftar wishlist.
- LOGOUT: Keluar dari sesi login.
- SAVE: Menyimpan status program ke file.
- QUIT: Keluar dari program.

## Compile Main
gcc -o main main.c adt/ArrayDin/ArrayDin.c adt/ArrayStat/ArrayStat.c adt/Barang/Barang.c adt/Circular Queue/circular_queue.c adt/LinkedList/doublyLinkedList.c adt/MesinKarakter/MesinKarakter.c adt/MesinKata/MesinKata.c adt/Queue/Queue.c adt/SetMap/setmap.c adt/Stack/stack.c adt/User/User.c util/util.c
