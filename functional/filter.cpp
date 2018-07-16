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
    for (int i = -5; i <= 5; i++)
        a.push_back(i);

    // 偶数のみ抽出
    vector<int> b;   
    copy_if(a.begin(), a.end(), back_inserter(b), [](int x) {return x % 2 == 0;});
    disp(b);      // -4 -2 0 2 4 

    // 負の数のみ抽出
    vector<int> c;   
    copy_if(a.begin(), a.end(), back_inserter(c), [](int x) {return x < 0;});
    disp(c);      // -5 -4 -3 -2 -1 

    return 0;
}
