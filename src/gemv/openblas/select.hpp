/**
 * Enable/Disable benchmarks
 */

#pragma once

#include "def.hpp"

#define BM_GEMV_OPENBLAS(type, m, n) \
	BENCHMARK_TEMPLATE(gemv__pmat_c__openblas, type, m, n); \
	BENCHMARK_TEMPLATE(gemv__pmat_r__openblas, type, m, n);
