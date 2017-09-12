#pragma once

#include "openblas/select.hpp"

#define BM_DOT_SIZE(type, size) \
	BM_DOT_OPENBLAS(type, size)

#define BM_DOT \
	BM_DOT_SIZE(float, 2) \
	BM_DOT_SIZE(float, 512) \
	BM_DOT_SIZE(float, 2048) \
	\
	BM_DOT_SIZE(float, 4096) \
	BM_DOT_SIZE(float, 8196) \
	BM_DOT_SIZE(float, 32768) \
	\
	BM_DOT_SIZE(float, 524288) \
	BM_DOT_SIZE(float, 1966080) \
	BM_DOT_SIZE(float, 3932160) \
	\
	BM_DOT_SIZE(float, 33554432) \
	BM_DOT_SIZE(float, 134217728) \
	BM_DOT_SIZE(float, 536870912) \
	\
	BM_DOT_SIZE(double, 2) \
	BM_DOT_SIZE(double, 256) \
	BM_DOT_SIZE(double, 1024) \
	\
	BM_DOT_SIZE(double, 2048) \
	BM_DOT_SIZE(double, 4096) \
	BM_DOT_SIZE(double, 16384) \
	\
	BM_DOT_SIZE(double, 262144) \
	BM_DOT_SIZE(double, 983040) \
	BM_DOT_SIZE(double, 1966080) \
	\
	BM_DOT_SIZE(double, 16777216) \
	BM_DOT_SIZE(double, 67108864) \
	BM_DOT_SIZE(double, 268435456)