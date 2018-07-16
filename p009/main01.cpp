/*
5000個以上の名前が書かれている46Kのテキストファイル filenames.txt を用いる. まずアルファベット順にソートせよ.

のち, 各名前についてアルファベットに値を割り振り, リスト中の出現順の数と掛け合わせることで, 名前のスコアを計算する.

たとえば, リストがアルファベット順にソートされているとすると, COLINはリストの938番目にある. またCOLINは 3 + 15 + 12 + 9 + 14 = 53 という値を持つ. よってCOLINは 938 × 53 = 49714 というスコアを持つ.

ファイル中の全名前のスコアの合計を求めよ.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iterator>

std::string read_sub() {
  std::string str;
  std::ifstream ifs("names.txt");
  ifs >> str;
  return str;
}

std::vector<std::string> search_all(std::string const &text, std::regex const &re) {
  std::vector<std::string> result;
  std::sregex_iterator iter(text.cbegin(), text.cend(), re);
  std::sregex_iterator end;
  for (;iter != end; iter++) {
    result.push_back(iter->str());
  }
  return result;
}

int calc(std::string str) {
  int rc = 0;
  for(auto c: str) {
    rc += c - 'A' + 1;
  }
  return rc;
}

int main() {
  std::regex re("\"([A-Z]+)\"");
  std::string str = read_sub();
  std::vector<std::string> v = search_all(str, re);

  for (auto &str: v) {
    std::regex re2("\"");
    str = std::regex_replace(str, re2, "");
  }
  
  sort(std::begin(v), std::end(v));

  long long int  idx = 1, sum = 0;
  for (auto str: v) {
    sum += (long long int)calc(str) * idx++;
  }

  std::cout << "sum = " << sum << std::endl;
}
