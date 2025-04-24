#ifndef SORTING_UTILS_H
#define SORTING_UTILS_H

#include <string.h>
#define MAX_WORD_LEN 100

// Bubble Sort untuk integer
void bubble_sort(int arr[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - pass - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = tmp;
            }
        }
    }
}

// Selection Sort untuk integer
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[idx_min]) idx_min = j;
        if (idx_min != i) {
            int tmp = arr[i]; arr[i] = arr[idx_min]; arr[idx_min] = tmp;
        }
    }
}

// Insertion Sort untuk integer
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// Merge Sort untuk integer
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort untuk integer
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot) { i++; int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp; }
    int tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Shell Sort untuk integer
void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j = i;
            while (j >= gap && arr[j - gap] > temp) { arr[j] = arr[j - gap]; j -= gap; }
            arr[j] = temp;
        }
}

// ========================== SORTING KATA ===============================

void bubble_sort_words(char arr[][MAX_WORD_LEN], int n) {
    char temp[MAX_WORD_LEN];
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]); strcpy(arr[j], arr[j + 1]); strcpy(arr[j + 1], temp);
            }
}

void selection_sort_words(char arr[][MAX_WORD_LEN], int n) {
    int min_idx;
    char temp[MAX_WORD_LEN];
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (strcmp(arr[j], arr[min_idx]) < 0) min_idx = j;
        if (min_idx != i) {
            strcpy(temp, arr[i]); strcpy(arr[i], arr[min_idx]); strcpy(arr[min_idx], temp);
        }
    }
}

void insertion_sort_words(char arr[][MAX_WORD_LEN], int n) {
    char key[MAX_WORD_LEN];
    for (int i = 1; i < n; i++) {
        strcpy(key, arr[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
    }
}

void merge_words(char arr[][MAX_WORD_LEN], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    char L[n1][MAX_WORD_LEN], R[n2][MAX_WORD_LEN];
    for (int i = 0; i < n1; i++) strcpy(L[i], arr[l + i]);
    for (int j = 0; j < n2; j++) strcpy(R[j], arr[m + 1 + j]);
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        strcpy(arr[k++], strcmp(L[i], R[j]) <= 0 ? L[i++] : R[j++]);
    while (i < n1) strcpy(arr[k++], L[i++]);
    while (j < n2) strcpy(arr[k++], R[j++]);
}

void merge_sort_words(char arr[][MAX_WORD_LEN], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_words(arr, l, m);
        merge_sort_words(arr, m + 1, r);
        merge_words(arr, l, m, r);
    }
}

int partition_words(char arr[][MAX_WORD_LEN], int low, int high) {
    char pivot[MAX_WORD_LEN], temp[MAX_WORD_LEN];
    strcpy(pivot, arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            strcpy(temp, arr[i]); strcpy(arr[i], arr[j]); strcpy(arr[j], temp);
        }
    }
    strcpy(temp, arr[i + 1]); strcpy(arr[i + 1], arr[high]); strcpy(arr[high], temp);
    return i + 1;
}

void quick_sort_words(char arr[][MAX_WORD_LEN], int low, int high) {
    if (low < high) {
        int pi = partition_words(arr, low, high);
        quick_sort_words(arr, low, pi - 1);
        quick_sort_words(arr, pi + 1, high);
    }
}

void shell_sort_words(char arr[][MAX_WORD_LEN], int n) {
    char temp[MAX_WORD_LEN];
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            strcpy(temp, arr[i]);
            int j = i;
            while (j >= gap && strcmp(arr[j - gap], temp) > 0) {
                strcpy(arr[j], arr[j - gap]);
                j -= gap;
            }
            strcpy(arr[j], temp);
        }
}

#endif
