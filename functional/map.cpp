#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void disp(const vector<T> &x) {
    for (size_t i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << endl;
}

int main(int argc, char **argv) {
    vector<int> a;
    for (int i = 0; i < 10; i++)
        a.push_back(i);

    // 二乗を計算
    transform(a.begin(), a.end(), a.begin(), [](int x) {return x*x;});
    disp(a);   // 0 1 4 9 16 25 36 49 64 81

    // 入力と出力の型が違ってもOK
    vector<char> b;
    transform(a.begin(), a.end(), back_inserter(b), [](int x){return 'A'+x%26;});
    disp(b);   // A B E J Q Z K X M D 

    // フィボナッチ数列
    vector<int> fib(100, 1);
    transform(fib.begin(), fib.end()-2, fib.begin()+1, fib.begin()+2, [](int x, int y) {return x+y;});
    disp(fib);  // 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 

    return 0;
}
