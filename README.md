# lib-cmp

This project was made to compare the performance of manually compiled OpenBLAS libraries with those provided by package manager repositories.

In high performance computing you might get incredibly poor performance by using high performance libraries that were not compiled properly. I made this benchmark to easily compare OpenBLAS' performance using 

## Requirements

- OpenBLAS (from your package manager)

## Installation

Initialize the submodules, compile OpenBLAS in the source folder, install Google Benchmark (`cmake ..` then `make` in a `build` folder you create in the Google Benchmark root folder) then OpenBLAS (just run `make` in the OpenBLAS root folder).

## Launch

Run `build.sh`, you'll find the respective benchmarks in `build-(repo/source)/bin/`. Run them, you should observe a huge gap in many cases between the benchmark that uses the source-compiled library and the benchmark that uses the package manager provided one.