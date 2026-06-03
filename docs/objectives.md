# Objectives

Tujuan penggunaan AMD Developer Cloud pada repo ini.

## 1. Validasi kompatibilitas ROCm

Saya ingin memastikan bahwa workload yang saya siapkan bisa berjalan langsung pada environment ROCm resmi.

## 2. Eksperimen HIP

Saya sedang menyiapkan contoh kernel HIP untuk:
- matrix multiplication
- bandwidth test
- compute-bound workload

## 3. Benchmark terukur

Saya ingin menyimpan hasil benchmark secara konsisten agar bisa dibandingkan dari waktu ke waktu.

## 4. Persiapan porting CUDA -> HIP

Salah satu tujuan utama saya adalah mempelajari proses porting dari CUDA ke HIP secara lebih praktis.

## 5. Reproducibility

Saya ingin hasil eksperimen bisa direproduksi oleh reviewer atau oleh saya sendiri di kemudian hari.

## 6. PyTorch ROCm evaluation

Saya juga ingin menguji workload berbasis PyTorch dengan backend ROCm untuk mengetahui perbedaan performa dan kompatibilitas.
