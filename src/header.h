#ifndef SORTING_UTILS_H
#define SORTING_UTILS_H

#include <string.h>

#define MAX_WORD_LEN 100

// Fungsi untuk mengurutkan array integer menggunakan Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - pass - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                // Tukar elemen jika tidak dalam urutan
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
}

// Fungsi untuk mengurutkan array string menggunakan Bubble Sort
void bubble_sort_words(char arr[][MAX_WORD_LEN], int n) {
    char temp[MAX_WORD_LEN];
    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - pass - 1; i++) {
            if (strcmp(arr[i], arr[i + 1]) > 0) {
                // Tukar jika arr[i] lebih besar secara leksikografis
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i + 1]);
                strcpy(arr[i + 1], temp);
            }
        }
    }
}

// Fungsi Selection Sort untuk array integer
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[idx_min]) {
                idx_min = j;
            }
        }
        // Tukar elemen minimum ke posisi saat ini
        if (idx_min != i) {
            int tmp = arr[i];
            arr[i] = arr[idx_min];
            arr[idx_min] = tmp;
        }
    }
}

// Fungsi Selection Sort untuk array string
void selection_sort_words(char arr[][MAX_WORD_LEN], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[idx_min]) < 0) {
                idx_min = j;
            }
        }
        // Tukar elemen minimum ke posisi saat ini
        if (idx_min != i) {
            char temp[MAX_WORD_LEN];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[idx_min]);
            strcpy(arr[idx_min], temp);
        }
    }
}

// Fungsi Insertion Sort untuk array integer
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Geser elemen yang lebih besar dari key ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Fungsi Insertion Sort untuk array string
void insertion_sort_words(char arr[][MAX_WORD_LEN], int n) {
    char key[MAX_WORD_LEN];
    for (int i = 1; i < n; i++) {
        strcpy(key, arr[i]);
        int j = i - 1;
        // Geser elemen yang lebih besar dari key ke kanan
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
    }
}

// Fungsi Merge Sort: penggabungan dua array terurut
void merge(int arr[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;
    int L[left_size], R[right_size];

    // Salin data ke array sementara L dan R
    for (int i = 0; i < left_size; i++) L[i] = arr[left + i];
    for (int j = 0; j < right_size; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    // Gabungkan kembali ke array utama
    while (i < left_size && j < right_size) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    // Salin sisa elemen jika ada
    while (i < left_size) arr[k++] = L[i++];
    while (j < right_size) arr[k++] = R[j++];
}

// Fungsi Merge Sort: penggabungan dua array string terurut
void merge_words(char arr[][MAX_WORD_LEN], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;
    
    // Alokasi array sementara
    char(*L)[MAX_WORD_LEN] = (char(*)[MAX_WORD_LEN])malloc(left_size * sizeof(char[MAX_WORD_LEN]));
    char(*R)[MAX_WORD_LEN] = (char(*)[MAX_WORD_LEN])malloc(right_size * sizeof(char[MAX_WORD_LEN]));
    
    if (!L || !R) {
        if (L) free(L);
        if (R) free(R);
        fprintf(stderr, "Gagal alokasi memori di merge_words\n");
        exit(EXIT_FAILURE);
    }

    // Salin data ke array sementara L dan R
    for (int i = 0; i < left_size; i++) 
        strcpy(L[i], arr[left + i]);
    for (int j = 0; j < right_size; j++) 
        strcpy(R[j], arr[mid + 1 + j]);

    int i = 0, j = 0, k = left;
    // Gabungkan kembali ke array utama
    while (i < left_size && j < right_size) {
        if (strcmp(L[i], R[j]) <= 0)
            strcpy(arr[k++], L[i++]);
        else
            strcpy(arr[k++], R[j++]);
    }

    // Salin sisa elemen jika ada
    while (i < left_size) 
        strcpy(arr[k++], L[i++]);
    while (j < right_size) 
        strcpy(arr[k++], R[j++]);
        
    // Bebaskan memori
    free(L);
    free(R);
}

// Fungsi rekursif Merge Sort
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Fungsi rekursif Merge Sort untuk array string
void merge_sort_words(char arr[][MAX_WORD_LEN], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_words(arr, left, mid);
        merge_sort_words(arr, mid + 1, right);
        merge_words(arr, left, mid, right);
    }
}

// Fungsi partisi untuk Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int idx = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            idx++;
            int tmp = arr[idx]; arr[idx] = arr[j]; arr[j] = tmp;
        }
    }

    // Tempatkan pivot pada posisi yang benar
    int tmp = arr[idx + 1]; arr[idx + 1] = arr[high]; arr[high] = tmp;
    return idx + 1;
}

// Fungsi partisi untuk Quick Sort pada array string
int partition_words(char arr[][MAX_WORD_LEN], int low, int high) {
    // Gunakan pivot sebagai elemen terakhir
    char pivot[MAX_WORD_LEN];
    strcpy(pivot, arr[high]);
    int idx = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            idx++;
            // Tukar elemen
            char temp[MAX_WORD_LEN];
            strcpy(temp, arr[idx]);
            strcpy(arr[idx], arr[j]);
            strcpy(arr[j], temp);
        }
    }

    // Tempatkan pivot pada posisi yang benar
    char temp[MAX_WORD_LEN];
    strcpy(temp, arr[idx + 1]);
    strcpy(arr[idx + 1], arr[high]);
    strcpy(arr[high], temp);
    
    return idx + 1;
}

// Fungsi utama Quick Sort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Fungsi utama Quick Sort untuk array string
void quick_sort_words(char arr[][MAX_WORD_LEN], int low, int high) {
    if (low < high) {
        int pi = partition_words(arr, low, high);
        quick_sort_words(arr, low, pi - 1);
        quick_sort_words(arr, pi + 1, high);
    }
}

// Fungsi Shell Sort untuk array integer
void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int value = arr[i];
            int j = i;
            // Geser elemen yang lebih besar sejauh gap
            while (j >= gap && arr[j - gap] > value) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = value;
        }
    }
}

// Fungsi Shell Sort untuk array string
void shell_sort_words(char arr[][MAX_WORD_LEN], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char value[MAX_WORD_LEN];
            strcpy(value, arr[i]);
            int j = i;
            // Geser elemen yang lebih besar sejauh gap
            while (j >= gap && strcmp(arr[j - gap], value) > 0) {
                strcpy(arr[j], arr[j - gap]);
                j -= gap;
            }
            strcpy(arr[j], value);
        }
    }
}

#endif