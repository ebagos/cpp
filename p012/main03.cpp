/*
    数値を1桁ごとに配列に格納して計算する
*/
#include <iostream>
#include <valarray>
#include <algorithm>

using namespace std;

#define MAXKETA 11
#define MAXREP 1000

void normalize(valarray<int>& x);
void mplus(valarray<int>& a, valarray<int>& result);
void mpower(valarray<int>& x, int n);
void printout(valarray<int>& val);

// 桁ごとに演算した後の桁あふれを1桁上に引き継ぐ
// このループを単純化するためにMAXKETAを+1した
void normalize(valarray<int>& x) {
    for (auto it = begin(x); it < (end(x) - 1); it++) {
        *(it+1) += *it / 10;
        *it %= 10;
    }
    *(end(x) - 1) = 0;  // 11桁目のオーバーフロウを防ぐ
}

// 足し算
void mplus(valarray<int>& a, valarray<int>& result) {
    result += a;
    normalize(result);
}

// べき乗
void mpower(valarray<int>& x, int n) {
    x[0] = 1;   // 掛算なので初期値を1にしておく
                // ｎにしないのはロジックを単純化するため
    for (int th = 0; th < n; th++) {
        x *= n; // xの各要素にnを掛ける
        normalize(x);
    }
}

// 表示用：関数化しておけばデバッグにも使える
void printout(valarray<int>& val) {
    /*
    for (int i = MAXKETA - 2; i >= 0; i--) {
        cout << val[i];
    }
    cout << endl;
    */
    // コメントアウト部分のほうが下のロジックよりわかりやすいか？
    auto it = end(val);
    --it;
    --it;
    for ( ; it >= begin(val); --it) {
        cout << *it;
    }
    cout << endl;
}

int main() {
    valarray<int> result(0, MAXKETA);
    for (int i = 1; i <= MAXREP; i++) {
        valarray<int> val(0, MAXKETA);
        mpower(val, i);
        mplus(val, result);
    }
    printout(result);
}
