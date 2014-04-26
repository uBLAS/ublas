#ifndef TESTS_HPP
#define TESTS_HPP
#include "kernels.hpp"
#include <vector>

struct perf
{
    std::size_t N, M, L, mflops;
};

std::vector< perf > runTests(std::size_t N, std::size_t M, std::size_t L);

#endif