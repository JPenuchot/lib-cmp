#pragma once

#include "openblas/select.hpp"

#define BM_GEMV_SIZE(type, m, n) \
	BM_GEMV_OPENBLAS(type, m, n)

#define BM_GEMV \
	BM_GEMV_SIZE(float, 1024, 512) \
	BM_GEMV_SIZE(float, 1023, 513) \
	BM_GEMV_SIZE(float, 1024, 1024) \
	BM_GEMV_SIZE(float, 102391, 1231)
