/*
  1以上、1000未満の整数で、3または5で割り切れるものの和を求める
*/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 一般的なC++プログラム
long p001_1() {
  long sum = 0;
  for (long i = 1; i < 1000; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}

/*
  仕様変更があったら大変、パラメータ化しようとして、だいたい以下の関数をつくることになる
  問題が簡単だからこれでもいいが、発想としては安易すぎる
*/
long p001_2(long min, long max, long md1, long md2) {
  long sum = 0;
  for (long i = min; i < max; i++) {
    if (i % md1 == 0 || i % md2 == 0) {
      sum += i;
    }
  }
  return sum;
}

/*
    せめて以下ぐらいにはしてほしい
    (まぁ、myfuncまでするのもやりすぎな気はする)
*/
bool myfilter(long n) {
    return (n % 3 == 0 || n % 5 == 0);
}

long myfunc(long n, long sum) {
    return sum + n;
}

long p001_2_2(long min, long max) {
    long sum = 0;
    for (long i = min; i < max; i++) {
        if (myfilter(i)) {
            sum = myfunc(i, sum);
        }
    }
    return sum;
}

/*
    あるいはラムダ関数で
    なれないと読みづらい
*/
long p001_2_3(long min, long max, long md1, long md2) {
    long sum = 0;
    for (long i = min; i < max; i++) {
        if ([md1, md2](long x) {return (x % md1 == 0 || x % md2 == 0);}(i)) {
            sum = [sum](long x) {return sum + x;} (i);  // やりすぎかも
        }
    }
    return sum;
}

//-------------------------------------------------------

/*
    C++11のfunctionalをつかって関数をパラメータとして渡した
    渡される関数はラムダ関数でもいい

*/
long p001_3(long min, long max, std::function<bool(long)> filter,
            std::function<long(long, long)> func) {
    long sum = 0;
    for (long i = min; i < max; i++) {
        if (filter(i) == true) {
            sum = func(i, sum);
            if (sum < 0) {
                std::cout << i << std::endl;
                return sum;
            }
        }
    }
    return sum;
}

/*
    ループを消して再帰で実現してみた
*/
long p001_4(long min, long max, long sum) {  //sum
    std::function<bool(long)> filter = myfilter;
    std::function<long(long, long)> func = myfunc;
    if (min == max) return sum;
    if (filter(min) == true) {
        return p001_4(min + 1, max, func(min, sum));
    } else {
        return p001_4(min + 1, max, sum);
    }
}

/*
    Vectorを使えるのならこうしたほうがスッキリ（C++11）
*/
long p001_5(long min, long max) {
    vector<long> a;
    for (long i = min; i < max; i++) {
        a.push_back(i);
    }

    vector<long> b;
    copy_if(a.begin(), a.end(), back_inserter(b), myfilter);
    return accumulate(b.begin(), b.end(), 0);
}

int main() {
    cout << p001_1() << endl;
    cout << p001_2(1, 1000, 3, 5) << endl;
    cout << p001_2_2(1, 1000) << endl;
    cout << p001_2_3(1, 1000, 3, 5) << endl;
    cout << p001_3(1, 1000, myfilter, myfunc) << endl;
    cout << p001_4(1, 1000, 0) << endl;
    cout << p001_5(1, 1000) << endl;
}