#pragma once

#include <benchmark/benchmark.h>

#include <numeric>

#include <cblas.h>

void openblas_gemv_c
	( const CBLAS_TRANSPOSE trans
	, const int m
	, const int n
	, const double alpha
	, const double *a
	, const int lda
	, const double *x
	, const int incx
	, const double beta
	, double *y
	, const int incy
){
		cblas_dgemv(CblasColMajor, trans, m, n, alpha, a, lda, x, incx, beta, y, incy);
}

void openblas_gemv_r
	( const CBLAS_TRANSPOSE trans
	, const int m
	, const int n
	, const double alpha
	, const double *a
	, const int lda
	, const double *x
	, const int incx
	, const double beta
	, double *y
	, const int incy
){
		cblas_dgemv(CblasRowMajor, trans, m, n, alpha, a, lda, x, incx, beta, y, incy);
}

void openblas_gemv_c
	( const CBLAS_TRANSPOSE trans
	, const int m
	, const int n
	, const float alpha
	, const float *a
	, const int lda
	, const float *x
	, const int incx
	, const float beta
	, float *y
	, const int incy
){
		cblas_sgemv(CblasColMajor, trans, m, n, alpha, a, lda, x, incx, beta, y, incy);
}

void openblas_gemv_r
	( const CBLAS_TRANSPOSE trans
	, const int m
	, const int n
	, const float alpha
	, const float *a
	, const int lda
	, const float *x
	, const int incx
	, const float beta
	, float *y
	, const int incy
){
		cblas_sgemv(CblasRowMajor, trans, m, n, alpha, a, lda, x, incx, beta, y, incy);
}


template< typename T
		, std::size_t M
		, std::size_t N
		>
static void gemv__pmat_c__openblas(benchmark::State& state) {
	std::vector<T> mat(M * N);
	std::vector<T> vec(N);
	std::vector<T> res(M);
	
	std::iota(mat.begin(), mat.end(), 0);
	std::iota(vec.begin(), vec.end(), 0);

	while(state.KeepRunning()){
		openblas_gemv_c
			( CblasNoTrans
			, M, N, 1
			, mat.data(), M
			, vec.data(), 1
			, 1.
			, res.data(), 1
		);
	}
}

template< typename T
		, std::size_t M
		, std::size_t N
		>
static void gemv__pmat_r__openblas(benchmark::State& state) {
	pg::pmat_r<T, M, N> mat;
	pg::pvector<T, N> vec;
	pg::pvector<T, M> res;
	
	std::iota(mat.begin(), mat.end(), 0);
	std::iota(vec.begin(), vec.end(), 0);

	while(state.KeepRunning()){
		openblas_gemv_r
			( CblasNoTrans
			, M, N, 1
			, mat.data(), N
			, vec.data(), 1
			, 1.
			, res.data(), 1
		);
	}
}
