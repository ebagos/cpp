#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    // 和を計算
    vector<int> a;
    for (int i = 0; i < 10; i++)
        a.push_back(i);
    cout << accumulate(a.begin(), a.end(), 1000) << endl;   // 1045

    // 文字列にも使える（+オペレータは文字の連結）
    vector<string> b;
    b.push_back("hello, ");
    b.push_back("world");
    b.push_back("!!");
    cout << accumulate(b.begin(), b.end(), string("")) << endl;   // hello, world!!

    // 二項演算子を指定
    cout << accumulate(a.begin(), a.end(), 1, [](int x, int y){return max(x, y);}) << endl; // 9

    return 0;
}
