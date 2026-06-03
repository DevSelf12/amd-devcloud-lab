#!/usr/bin/env bash
set -euo pipefail

echo "[setup] check ROCm environment"

if ! command -v rocminfo >/dev/null 2>&1; then
  echo "[warn] rocminfo not found."
  echo "Pastikan ROCm sudah terinstall sebelum jalankan eksperimen HIP."
fi

if ! command -v hipcc >/dev/null 2>&1; then
  echo "[warn] hipcc not found."
  echo "Install ROCm/HIP toolchain sesuai environment AMD Developer Cloud."
else
  echo "[ok] hipcc found: $(command -v hipcc)"
fi

if command -v python3 >/dev/null 2>&1; then
  echo "[ok] python3 found: $(python3 --version)"
else
  echo "[warn] python3 not found."
fi

echo "[setup] selesai."
