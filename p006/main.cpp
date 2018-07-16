/*
最初の10個の自然数について, その二乗の和は,
1^2 + 2^2 + ... + 10^2 = 385

最初の10個の自然数について, その和の二乗は,
(1 + 2 + ... + 10)^2 = 3025

これらの数の差は 3025 - 385 = 2640 となる.

同様にして, 最初の100個の自然数について二乗の和と和の二乗の差を求めよ.
*/
/*
    C/C++では加算、減算でのoverflow/underflowは無視されるので
    プログラムが対応しなければならい
    しかし、本問題ではその必要性がない！

    uintmax_tの取りうる最大値から十分小さな値で制限をつける、というのが現実的
*/
#include <iostream>
#include <cstdint>

uintmax_t powsum(const uintmax_t n) {
    uintmax_t sum = 0;

    for (uintmax_t i = 1; i <= n; i++) {
        sum += i * i;
        std::cout << "powsum : " << sum << std::endl;
    }
    return sum;
}

uintmax_t sumpow(const uintmax_t n) {
    // (1+n) * n / 2でいいのだけど・・・
    uintmax_t sum = 0;
    for (uintmax_t i = 1; i <= n; i++) {
        sum += i;
        std::cout << "sumpow : " << sum << std::endl;
    }
    return sum * sum;
}

int main() {
    std::cout << "100 => " << sumpow(100) << " - " << powsum(100) 
            << " = " << sumpow(100) - powsum(100) << std::endl;
}