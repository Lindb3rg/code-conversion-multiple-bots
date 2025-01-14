#include <iostream>
#include <iomanip>
#include <chrono>

double calculate(long long iterations, int param1, int param2) {
    double result = 1.0;
    for (long long i = 1; i <= iterations; ++i) {
        double j = static_cast<double>(i) * param1 - param2;
        result -= 1.0 / j;
        j = static_cast<double>(i) * param1 + param2;
        result += 1.0 / j;
    }
    return result;
}

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    double result = calculate(100000000LL, 4, 1) * 4;
    auto end_time = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Result: " << result << std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Execution Time: " << duration.count() / 1e6 << " seconds" << std::endl;

    return 0;
}