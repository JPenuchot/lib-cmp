#include <benchmark/benchmark.h>

#include "dot/select.hpp"
#include "gemv/select.hpp"

BM_DOT
BM_GEMV

BENCHMARK_MAIN();
