#include <cstdint>
#include <iostream>
#include <limits>

using u64 = std::uint64_t;

int main() {
    constexpr u64 MAX_SAFE = (std::numeric_limits<u64>::max() - 1) / 3;

    for (u64 start = 1; start != 0; ++start) {
        u64 n = start;
        u64 iterations = 0;

        while (n != 1) {
            if (n & 1) {
                // Prevent uint64_t overflow in 3*n+1
                if (n > MAX_SAFE) {
                    std::cout << "Overflow at start: " << start << ", n:" << n << '\n';
                    break;
                }

                // Two Collatz steps at once:
                // n -> 3n+1 -> (3n+1)/2
                n = (3 * n + 1) >> 1;
                iterations += 2;
            } else {
                n >>= 1;
                ++iterations;
            }
        }

        if (n == 1) std::cout << "Start: " << start << ", Iterations: " << iterations << '\n';
    }
}