#include <benchmark/benchmark.h>

#include <numeric>

#include <cblas.h>

float openblas_dot(const int n, float* x, const int incx, float* y, const int incy)
{ return cblas_sdot(n, x, incx, y, incy); }

double openblas_dot(const int n, double* x, const int incx, double* y, const int incy)
{ return cblas_ddot(n, x, incx, y, incy); }


template <typename T, std::size_t size>
static void dot__pvector__openblas(benchmark::State& state) {
	std::vector<T> p(size);
	std::iota(p.begin(), p.end(), 0);
	while(state.KeepRunning())
		benchmark::DoNotOptimize(openblas_dot(size, p.data(), 1, p.data(), 1));
}
