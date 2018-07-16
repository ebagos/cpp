/*
    数値を1桁ごとに配列に格納して計算する
*/
#include <iostream>
#include <valarray>
#include <algorithm>
#include <exception>
#include <cstdint>

using namespace std;

void normalize(valarray<uint64_t>& x);
void mplus(valarray<uint64_t>& a, valarray<uint64_t>& result);
void mpower(valarray<uint64_t>& x, uint64_t n);
void printout(valarray<uint64_t>& val);

// 桁ごとに演算した後の桁あふれを1桁上に引き継ぐ
// このループを単純化するためにMAXKETAを+1した
void normalize(valarray<uint64_t>& x) {
    for (auto it = begin(x); it < (end(x) - 1); it++) {
        *(it+1) += *it / 10;
        *it %= 10;
    }
    *(end(x) - 1) = 0;  // 11桁目のオーバーフロウを防ぐ
}

// 足し算
void mplus(valarray<uint64_t>& a, valarray<uint64_t>& result) {
    result += a;
    normalize(result);
}

// べき乗
void mpower(valarray<uint64_t>& x, uint64_t n) {
    x[0] = n;
    for (uint64_t th = 1; th < n; th++) {
        x *= n; // xの各要素にnを掛ける
        normalize(x);
    }
}

// 表示用：関数化しておけばデバッグにも使える
void printout(valarray<uint64_t>& val) {
    /*
    for (uint64_t i = MAXKETA - 2; i >= 0; i--) {
        cout << val[i];
    }
    cout << endl;
    */
    // コメントアウト部分のほうが下のロジックよりわかりやすいか？
    for ( auto it = end(val) - 2; it >= begin(val); --it) {
        cout << *it;
    }
    cout << endl;
}

int main() try {
    const uint64_t MAXKETA = 11;
    const uint64_t MAXREP = 1000;

    valarray<uint64_t> result((uint64_t)0, MAXKETA);
    for (uint64_t i = 1; i <= MAXREP; i++) {
        valarray<uint64_t> val((uint64_t)0, MAXKETA);
        mpower(val, i);
        mplus(val, result);
    }
    printout(result);
} catch (bad_alloc& e) {
    cerr << "Not enough memory !\n";
    cerr << e.what() << endl;
} catch (...) {
    cerr << "Unexpected error !\n";
}
/*
 catch (const char *e) {
    cerr << e << endl;
}
*/