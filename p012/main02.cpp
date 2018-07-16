/*
    数値を1桁ごとに配列に格納して計算する
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXKETA 11
#define MAXREP 1000

void normalize(vector<int>& x);
void mplus(vector<int>& a, vector<int>& result);
void mpower(vector<int>& x, int n);

// 桁ごとに演算した後の桁あふれを1桁上に引き継ぐ
void normalize(vector<int>& x) {
    int keta = x.size();
    for (int i = 0; i < keta - 1; i++) {
        x[i + 1] += x[i] / 10;
        x[i] %= 10;
    }
    x[keta - 1] = 0;  // overflowを防ぐため
}

// 足し算
void mplus(vector<int>& a, vector<int>& result) {
    int keta = a.size();
    for (int i = 0; i < keta; i++) {
        result[i] += a[i];
    }
    normalize(result);
}

// べき乗
void mpower(vector<int>& x, int n) {
    x[0] = 1;   // 掛算なので初期値を1にしておく
                // ｎにしないのはロジックを単純化するため
    for (int th = 0; th < n; th++) {
        for_each(x.begin(), x.end(), [n](int& z){z *= n;});
        normalize(x);
    }
}

// 表示用：関数化しておけばデバッグにも使える
void printout(vector<int> val) {
    for (int i = MAXKETA - 2; i >= 0; i--) {
        cout << val[i];
    }
    cout << endl;
}

int main() {
    vector<int> result;
    for (int i = 0; i < MAXKETA; i++) {
        result.push_back(0);
    }
    for (int i = 1; i <= MAXREP; i++) {
        vector<int> val;
        for (int j = 0; j < MAXKETA; j++) {
            val.push_back(0);
        }
        mpower(val, i);
        mplus(val, result);
    }
    printout(result);
}
