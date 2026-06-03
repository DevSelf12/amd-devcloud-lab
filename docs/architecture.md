# Arsitektur Eksperimen

## Overview

Arsitektur repo ini sederhana dan difokuskan pada reproducibility:

```
User / Reviewer
      │
      ▼
  README.md (tujuan & konteks)
      │
      ▼
  docs/ (objectives + arsitektur)
      │
      ▼
  experiments/ (kode eksperimen)
      │
      ▼
  benchmarks/ (hasil & metrik)
      │
      ▼
  scripts/ (setup & automasi)
```

## Kenapa struktur ini?

Struktur ini dipilih agar reviewer AMD Developer Cloud bisa langsung melihat:
1. alasan penggunaan
2. bentuk eksperimen
3. metrik yang ingin diukur
4. kesiapan reproducibility

## Target environment

- OS: Ubuntu 22.04
- Stack: ROCm 6.x
- Framework: PyTorch ROCm / HIP
- Language: C++ (HIP), Python (benchmark orchestration)

## Workflow

1. Setup environment dengan `scripts/setup_dev.sh`
2. Build eksperimen di `experiments/`
3. Jalankan benchmark
4. Catat hasil ke `benchmarks/results.md`

## Design principle

- minimal dependency
- mudah direproduksi
- fokus pada workload nyata, bukan demo abstrak
