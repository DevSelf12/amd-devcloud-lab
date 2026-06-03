# amd-devcloud-lab

Repo ini disiapkan khusus untuk mendukung aplikasi **AMD Developer Cloud**.

## Tujuan

Menunjukkan kebutuhan nyata terhadap akses AMD Developer Cloud untuk:
- eksperimen **ROCm** dan **HIP**
- benchmark workload GPU AMD
- reproducibility pada lingkungan AMD resmi
- persiapan porting workload dari CUDA ke HIP

## Kenapa butuh AMD Developer Cloud?

Saya sedang mengerjakan workload yang membutuhkan environment AMD GPU langsung, bukan hanya simulasi lokal.

Beberapa alasan utama:
- memastikan kompatibilitas dengan stack ROCm resmi
- menguji kernel HIP di device target
- mengevaluasi performa PyTorch dengan ROCm
- menyiapkan baseline benchmark yang bisa direproduksi

## Fokus repo ini

Repo ini bukan repo produksi, melainkan **lab notebook teknis** berisi:
- contoh kernel HIP
- skrip benchmark
- catatan setup ROCm
- arsitektur eksperimen
- tujuan penggunaan AMD Developer Cloud

## Struktur

```
amd-devcloud-lab/
├── README.md
├── LICENSE
├── .gitignore
├── benchmarks/
│   └── results.md
├── docs/
│   ├── architecture.md
│   └── objectives.md
├── experiments/
│   └── matrix_mul_hip.cpp
└── scripts/
    └── setup_dev.sh
```

## Quick look

```bash
bash scripts/setup_dev.sh
```

## Catatan penting

Repo ini sengaja dibuat agar reviewer bisa melihat:
- kebutuhan teknis yang jelas
- rencana eksperimen terstruktur
- alasan mengapa environment AMD resmi diperlukan
