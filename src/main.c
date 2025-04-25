#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../src/header.h"

#define MAX_DATA 2000000
#define MAX_WORD_LEN 100

void muat_angka(const char *path, int array[], int jumlah) {
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Gagal membuka file angka");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < jumlah; i++) {
        if (fscanf(file, "%d", &array[i]) != 1) break;
    }

    fclose(file);
}

void muat_kata(const char *path, char array[][MAX_WORD_LEN], int jumlah) {
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Gagal membuka file kata");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < jumlah; i++) {
        if (fscanf(file, "%s", array[i]) != 1) break;
    }

    fclose(file);
}

void salin_array(int tujuan[], int sumber[], int n) {
    for (int i = 0; i < n; i++) {
        tujuan[i] = sumber[i];
    }
}

void salin_array_kata(char tujuan[][MAX_WORD_LEN], char sumber[][MAX_WORD_LEN], int n) {
    for (int i = 0; i < n; i++) {
        strcpy(tujuan[i], sumber[i]);
    }
}

int menu_jenis_data() {
    int pilihan;
    printf("=== PILIH TIPE DATA ===\n");
    printf("1. Angka\n2. Kata\nPilihan Anda [1-2]: ");
    scanf("%d", &pilihan);
    if (pilihan != 1 && pilihan != 2) {
        printf("Pilihan tidak sah.\n");
        exit(EXIT_FAILURE);
    }
    return pilihan;
}

int menu_jumlah_data() {
    int opsi, ukuran[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};
    printf("\n=== PILIH JUMLAH DATA ===\n");
    for (int i = 0; i < 8; i++) {
        printf("%d. %d data\n", i + 1, ukuran[i]);
    }
    printf("Pilihan Anda [1-8]: ");
    scanf("%d", &opsi);
    if (opsi < 1 || opsi > 8) {
        printf("Pilihan tidak sah.\n");
        exit(EXIT_FAILURE);
    }
    return ukuran[opsi - 1];
}

void cetak_header() {
    printf("\n+-------------------------------+------------------------------+-------------------------------+\n");
    printf("|     Algoritma Yang Digunakan  | Waktu Yang Diperlukan (Detik) | Memori Yang Digunakan (MB)     |\n");
    printf("+-------------------------------+------------------------------+-------------------------------+\n");
}

void cetak_footer() {
    printf("+-------------------------------+------------------------------+-------------------------------+\n");
}

int main() {
    int tipe = menu_jenis_data();
    int jumlah = menu_jumlah_data();

    printf("\nMenjalankan pengurutan sebanyak %d data...\n", jumlah);
    cetak_header();

    clock_t mulai, selesai;
    double durasi;

    if (tipe == 1) {
        int *data_awal = malloc(sizeof(int) * MAX_DATA);
        if (!data_awal) {
            printf("Gagal alokasi memori.\n");
            return 1;
        }

        muat_angka("../data/data_angka.txt", data_awal, jumlah);
        int *data = malloc(sizeof(int) * jumlah);

        const char *nama_sort[] = {
            "Bubble Sort (int)", "Selection Sort (int)", "Insertion Sort (int)",
            "Merge Sort (int)", "Quick Sort (int)", "Shell Sort (int)"
        };
        void (*fungsi_sort[])(int[], int) = {
            bubble_sort, selection_sort, insertion_sort,
            NULL, NULL, shell_sort
        };

        for (int i = 0; i < 6; i++) {
            salin_array(data, data_awal, jumlah);
            mulai = clock();
            if (fungsi_sort[i]) {
                fungsi_sort[i](data, jumlah);
            } else if (i == 3) {
                merge_sort(data, 0, jumlah - 1);
            } else if (i == 4) {
                quick_sort(data, 0, jumlah - 1);
            }
            selesai = clock();
            durasi = ((double)(selesai - mulai)) / CLOCKS_PER_SEC;
            printf("| %-30s | %26.3f | %29.2f |\n", nama_sort[i], durasi, sizeof(int) * jumlah / (1024.0 * 1024.0));
        }

        free(data_awal);
        free(data);
    } else {
        // Alokasi dan inisialisasi array untuk data kata awal
        char (*kata_awal)[MAX_WORD_LEN] = malloc(sizeof(char[MAX_WORD_LEN]) * jumlah);
        if (!kata_awal) {
            printf("Gagal alokasi memori untuk kata awal.\n");
            return 1;
        }
        
        // Muat data kata dari file
        muat_kata("../data/data_kata.txt", kata_awal, jumlah);
        
        // Alokasi array untuk data kata yang akan diurutkan
        char (*kata)[MAX_WORD_LEN] = malloc(sizeof(char[MAX_WORD_LEN]) * jumlah);
        if (!kata) {
            printf("Gagal alokasi memori untuk kata.\n");
            free(kata_awal);
            return 1;
        }

        const char *nama_sort[] = {
            "Bubble Sort (kata)", "Selection Sort (kata)", "Insertion Sort (kata)",
            "Merge Sort (kata)", "Quick Sort (kata)", "Shell Sort (kata)"
        };

        // Jalankan dan ukur waktu untuk setiap algoritma sorting
        for (int i = 0; i < 6; i++) {
            // Salin data kata awal ke array yang akan diurutkan
            salin_array_kata(kata, kata_awal, jumlah);
            
            mulai = clock();
            
            // Panggil fungsi sorting yang sesuai
            switch (i) {
                case 0:
                    bubble_sort_words(kata, jumlah);
                    break;
                case 1:
                    selection_sort_words(kata, jumlah);
                    break;
                case 2:
                    insertion_sort_words(kata, jumlah);
                    break;
                case 3:
                    merge_sort_words(kata, 0, jumlah - 1);
                    break;
                case 4:
                    quick_sort_words(kata, 0, jumlah - 1);
                    break;
                case 5:
                    shell_sort_words(kata, jumlah);
                    break;
            }
            
            selesai = clock();
            durasi = ((double)(selesai - mulai)) / CLOCKS_PER_SEC;
            
            // Hitung penggunaan memori (ukuran array kata)
            double memori = sizeof(char[MAX_WORD_LEN]) * jumlah / (1024.0 * 1024.0);
            
            printf("| %-30s | %26.3f | %29.2f |\n", nama_sort[i], durasi, memori);
        }

        // Bebaskan memori
        free(kata_awal);
        free(kata);
    }

    cetak_footer();
    return 0;
}