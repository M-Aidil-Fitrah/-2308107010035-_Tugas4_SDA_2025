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

// Fungsi rekursif Merge Sort
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

// Fungsi utama Quick Sort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
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

#endif