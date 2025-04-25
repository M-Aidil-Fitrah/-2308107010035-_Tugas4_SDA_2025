# Tugas 4 - Struktur Data dan Algoritma (Kelas D)

**Nama:** Muhammad Aidil Fitrah  
**NPM:** 2308107010035  

---

## Penjelasan Tentang Tugas

### Deskripsi  
Tugas ini merupakan bagian dari mata kuliah **Struktur Data dan Algoritma** di Program Studi Informatika USK. Fokus utama dari tugas ini adalah mengimplementasikan dan menganalisis performa berbagai algoritma **sorting** (pengurutan data) dalam hal **waktu eksekusi** dan **penggunaan memori** pada dataset berskala besar (hingga 2 juta data).

---

## Algoritma yang Diimplementasikan  

Terdapat enam algoritma sorting yang dianalisis dan diuji dalam tugas ini:

- Bubble Sort  
- Selection Sort  
- Insertion Sort  
- Merge Sort  
- Quick Sort  
- Shell Sort  

Setiap algoritma diimplementasikan dalam bahasa **C**, dengan masing-masing fungsi ditulis dalam file header (`.h`) dan dipanggil dari file utama (`.c`).

---

## Dataset

Pengujian dilakukan menggunakan dua jenis dataset:

- **Data angka** sebanyak 2.000.000 baris  
- **Data kata (string)** sebanyak 2.000.000 baris  

Dataset dihasilkan menggunakan program generator yang diberikan dalam instruksi tugas dan disimpan dalam file `data_angka.txt` dan `data_kata.txt`.

---

## Pengerjaan

Pengujian dilakukan menggunakan dataset dengan ukuran bertahap sebagai berikut:

- 10.000  
- 50.000  
- 100.000  
- 250.000  
- 500.000  
- 1.000.000  
- 1.500.000  
- 2.000.000  

---

## Hasil dan Analisis

- Algoritma **Bubble Sort**, **Selection Sort**, dan **Insertion Sort** menunjukkan performa lambat dengan kompleksitas waktu **O(n²)**, terutama untuk dataset besar.
- **Merge Sort** dan **Quick Sort** adalah algoritma paling efisien dengan waktu eksekusi tercepat (kompleksitas **O(n log n)**).
- **Shell Sort** memberikan hasil yang cukup baik dan stabil, berada di antara performa algoritma O(n²) dan O(n log n).
- Sorting data **kata (string)** membutuhkan waktu lebih lama dibanding angka karena proses perbandingan string lebih kompleks.
- Semua algoritma menggunakan array tetap, sehingga penggunaan memori relatif stabil. **Merge Sort** menggunakan array tambahan saat proses penggabungan, tetapi tidak menyebabkan lonjakan signifikan.

---

