/*
n × (n - 1) × ... × 3 × 2 × 1 を n! と表す.

例えば, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800 となる.
この数の各桁の合計は 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27 である.

では, 100! の各桁の数字の和を求めよ.
*/

#include <iostream>
#include <valarray>
#include <algorithm>
#include <exception>
#include <cstdint>
#include <numeric>

using namespace std;

// 各要素が0から9になるよう平準化を行う
// アクセス違反が起きないようend(x)-1未満のループ
void normalize(valarray<uint32_t>& x) {
    for (auto it = begin(x); it < (end(x) - 1); it++) {
        *(it+1) += *it / 10;
        *it %= 10;
    }
    *(end(x) - 1) = 0;  // 最終桁のオーバーフローを防ぐ
}

// 階乗計算
valarray<uint32_t>& factorial(valarray<uint32_t>& x, uint32_t n) {
    x[0] = 1;
    for (uint32_t th = 1; th <= n; th++) {
        x *= th; // xの各要素にnを掛ける
        normalize(x);
    }
    return x;
}

// 全体をtry-catchで覆うことで例外を処理できることを示しただけ
int main() try {
    const uint32_t MAXKETA = 200 + 1;
    const uint32_t MAXREP = 100;

    valarray<uint32_t> val((uint32_t)0, MAXKETA);
    val = factorial(val, MAXREP);
    uint32_t result = accumulate(begin(val), end(val), 0);  // 最初に0クリアしているから使わない桁を判断する必要なし
    cout << "The answer is " << result << "." << endl;
} catch (bad_alloc& e) {
    cerr << "Not enough memory !\n";
    cerr << e.what() << endl;
} catch (...) {
    cerr << "Unexpected error !\n";
}
