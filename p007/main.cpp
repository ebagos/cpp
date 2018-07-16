/*
正の整数に以下の式で繰り返し生成する数列を定義する.

    n → n/2 (n が偶数)

    n → 3n + 1 (n が奇数)

13からはじめるとこの数列は以下のようになる.
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

13から1まで10個の項になる. この数列はどのような数字からはじめても最終的には 1 になると考えられているが, まだそのことは証明されていない(コラッツ問題)

さて, 100万未満の数字の中でどの数字からはじめれば最長の数列を生成するか.

注意: 数列の途中で100万以上になってもよい
*/
#include <iostream>
#include <map>

#define MAX 1000000

using namespace std;

long long int collatz(const int n) {
  int count = 1;
  long long int m = (long long int)n;
  while (m > 1) {
    if (m % 2 == 0) {
      m = m / 2;
    } else {
      m = m * 3 + 1;
    }
    count++;
  }
  return count;
}

map<int, long long int> magic;
// 数が大きいと時間がかかりすぎる
long long int collatz_(int n) {
  int count = 1;
  long long int m = (long long int)n;
  while (m > 1) {
    if (magic[n] != 0) return magic[n];
    if (m % 2 == 0) {
      m = m / 2;
    } else {
      m = m * 3 + 1;
    }
    count++;
    magic[m] = count;
  }
  magic[n] = count;
  return count;
}

long long int box[MAX+1] = {0};
// 早いけどメモリ食い
long long int _collatz_(int n) {
  int count = 1;
  long long int m = (long long int)n;
  while (m > 1) {
    if (n < MAX) {
      if (box[n] != 0) return box[n];
    }
    if (m % 2 == 0) {
      m = m / 2;
    } else {
      m = m * 3 + 1;
    }
    count++;
    if (m < MAX) box[m] = count;
  }
  if (n < MAX) box[n] = count;
  return count;
}

int main() {
  std::cout << "start !!\n";
  int max = 0;
  int key = 0;

  for (int i = 2; i < MAX; i++) {
    long long int rc = collatz(i);
//    std::cout << i << "のとき " << rc << "回" <<std::endl;
//      magic.insert(std::pair<int,int>(i, rc));
    if (max < rc) {
      max = rc;
      key = i;
    }
  }
  std::cout << "key=" << key << std::endl;
  std::cout << "max=" << max << std::endl;

  std::cout << "910107 -> " << collatz(910107) << std::endl;
  std::cout << "837799 -> " << collatz(837799) << std::endl;

  for (int i = 2; i < MAX; i++) {
    long long int rc = _collatz_(i);
//    std::cout << i << "のとき " << rc << "回" <<std::endl;
//      magic.insert(std::pair<int,int>(i, rc));
    if (max < rc) {
      max = rc;
      key = i;
    }
  }
  std::cout << "key=" << key << std::endl;
  std::cout << "max=" << max << std::endl;

  std::cout << "910107 -> " << _collatz_(910107) << std::endl;
  std::cout << "837799 -> " << _collatz_(837799) << std::endl;
}
