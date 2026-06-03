#include <hip/hip_runtime.h>
#include <iostream>
#include <vector>
#include <cstdlib>

__global__ void matrix_mul_kernel(const float* A, const float* B, float* C, int N) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < N && col < N) {
        float value = 0.0f;
        for (int k = 0; k < N; ++k) {
            value += A[row * N + k] * B[k * N + col];
        }
        C[row * N + col] = value;
    }
}

int main() {
    const int N = 256;
    size_t bytes = N * N * sizeof(float);

    std::vector<float> h_A(N * N, 1.0f);
    std::vector<float> h_B(N * N, 2.0f);
    std::vector<float> h_C(N * N, 0.0f);

    float *d_A, *d_B, *d_C;
    hipMalloc(&d_A, bytes);
    hipMalloc(&d_B, bytes);
    hipMalloc(&d_C, bytes);

    hipMemcpy(d_A, h_A.data(), bytes, hipMemcpyHostToDevice);
    hipMemcpy(d_B, h_B.data(), bytes, hipMemcpyHostToDevice);

    dim3 block(16, 16);
    dim3 grid((N + block.x - 1) / block.x, (N + block.y - 1) / block.y);

    hipLaunchKernelGGL(matrix_mul_kernel, grid, block, 0, 0, d_A, d_B, d_C, N);
    hipDeviceSynchronize();

    hipMemcpy(h_C.data(), d_C, bytes, hipMemcpyDeviceToHost);

    bool ok = true;
    for (int i = 0; i < N * N; ++i) {
        if (h_C[i] != static_cast<float>(N) * 2.0f) {
            ok = false;
            break;
        }
    }

    std::cout << "[matrix_mul_hip] N=" << N << " result=" << (ok ? "PASS" : "FAIL") << "\n";

    hipFree(d_A);
    hipFree(d_B);
    hipFree(d_C);
    return ok ? 0 : 1;
}
