# Tugas 4 Struktur Data dan Algoritma (Kelas D)

Nama : Muhammad Aidil Fitrah
NPM : 2308107010035

# Penjelasan Tentang Tugas
# Deskripsi
Tugas ini merupakan bagian dari mata kuliah Struktur Data dan Algoritma di Informatika USK. Fokus utama dari tugas ini adalah mengimplementasikan dan menganalisis performa berbagai algoritma sorting (pengurutan data) dalam hal waktu eksekusi dan penggunaan memori pada dataset dalam skala besar (hingga 2 juta data).

# Algoritma Yang Diimplementasikan
Terdapat enam algoritma sorting yang dianalisis dan diuji dalam tugas ini:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Shell Sort
Setiap algoritma diimplementasikan dalam bahasa C, dengan masing-masing fungsi berada dalam file header (.h), dan dipanggil dari file utama (.c). Komentar penjelas dituliskan di atas setiap fungsi untuk mempermudah pemahaman kode.

# Dataset
Pengujian dilakukan menggunakan dua jenis dataset:
- Data angka sebanyak 2.000.000 baris
- Data kata (string) sebanyak 2.000.000 baris
Dataset dihasilkan menggunakan program generator yang tersedia pada instruksi tugas, dan disimpan dalam file data_angka.txt dan data_kata.txt.

# Pengerjaan
Pengujian dilakukan dengan dataset berukuran bertahap:
- 10.000
- 50.000
- 100.000
- 250.000
- 500.000
- 1.000.000
- 1.500.000
- 2.000.000

# Hasil dan Analisis
- Algoritma Bubble Sort, Selection Sort, dan Insertion Sort menunjukkan performa lambat dengan kompleksitas waktu O(n²), terutama untuk dataset besar.
- Merge Sort dan Quick Sort tampil sebagai yang paling efisien, dengan waktu eksekusi yang jauh lebih cepat (O(n log n)).
- Shell Sort berada di tengah, menunjukkan hasil yang cukup baik meskipun tidak secepat Merge dan Quick Sort.
- Sorting kata (string) membutuhkan waktu lebih lama dibanding angka karena perbandingan string lebih kompleks.
- Semua algoritma menggunakan array tetap sehingga memori relatif stabil, namun Merge Sort menggunakan array tambahan saat penggabungan.
