/*
13195 の素因数は 5, 7, 13, 29 である
600851475143 の素因数のうち最大のものを求めよ
*/
// 32ビット幅では計算できない

#include <iostream>
#include <cstdint>

uintmax_t factor(uintmax_t n) {
    uintmax_t x = 2;
    while (x * x <= n) {        // 探索数を減らすための条件
        while (n % x == 0) {
            n /= x;
        }
        x++;
    }
    return n == 1 ? x : n;
}

int main() {
   std::cout << "600851475143の最大の素因数 = " << factor(600851475143) << std::endl ;
}