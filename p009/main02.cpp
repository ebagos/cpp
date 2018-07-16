/*
5000個以上の名前が書かれている46Kのテキストファイル filenames.txt を用いる. まずアルファベット順にソートせよ.

のち, 各名前についてアルファベットに値を割り振り, リスト中の出現順の数と掛け合わせることで, 名前のスコアを計算する.

たとえば, リストがアルファベット順にソートされているとすると, COLINはリストの938番目にある. またCOLINは 3 + 15 + 12 + 9 + 14 = 53 という値を持つ. よってCOLINは 938 × 53 = 49714 というスコアを持つ.

ファイル中の全名前のスコアの合計を求めよ.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <numeric>
#include <cstdint>

// stringの配列を使用するので何気にメモリを消費しそう
std::string read_sub() {
  try {
    std::string str;
    std::ifstream ifs("names.txt");
    ifs >> str;
    return str;
  } catch(...) {
    std::cerr << "Error occurred\n";
    exit(-1);
  }
}

std::vector<std::string> split(std::string& str) {
  try {
    std::vector<std::string> v;
    std::string sub;
    std::string sss = "[,\"]";
    std::regex re(sss);

    std::istringstream stream(std::regex_replace(str, re, " "));

    while(std::getline(stream, sub, ' ')) {
      if (sub != "")
        v.push_back(sub);
    }
    return v;
  } catch (...) {
    std::cerr << "closing...\n";
    exit(-2);
  }
}

int calc(std::string str) {
  return std::accumulate(str.begin(), str.end(), 0, [](int x, char c) { return x + c - 'A' + 1; });
}

/* 末尾再起を使ったらかえってわかりづらくなった・・・
uint64_t calcu(std::vector<std::string> v, int idx, uint64_t sum) {
  std::vector<std::string>::iterator it = v.begin() + idx - 1;
  if (it == v.end()) {
    return sum;
  } else {
    uint64_t rc = std::accumulate((*it).begin(), (*it).end(), 0, [](uint64_t x, char c) { return x + c - 'A' + 1; });
    return calcu(v, idx + 1, sum + rc * idx);
  }
}
*/

int main() {
  std::string str = read_sub();
  std::vector<std::string> v = split(str);
  std::vector<std::string>::iterator it;

  sort(v.begin(), v.end());

  uint64_t idx, sum = 0;
  for (it = v.begin(), idx = 1; it < v.end(); it++, idx++) {
    sum += (uint64_t)calc(*it) * idx;
  }
  std::cout << "sum = " << sum << std::endl;
//  std::cout << "sum = " << calcu(v, 1, 0) << std::endl;
}
