/*
以下の4言語、4つの挨拶を対話的に表示するプログラムを作成せよ

| 　　 |  日本語   |     英語      | フランス語  |    ドイツ語      |
|:---:|:--------:|:------------: |:---------:|:--------------:|
| 朝　 | おはよう　 | Good moring  |  Bonjour  |  Guten Morgen   |
| 昼　 | こんにちは |    Hello     |  Bonjour  |    Guten Tag    |
| 夜　 | こんばんは | Good evening |  Bonsoir  |   Guten Abend   |
| 別れ | さようなら |   Good-by    | Au revoir | Auf Wiedersehen |

プログラムは、
1. 最初の入力で言語選択
1. 次の選択でシチュエーション選択
1. 最初に戻る、または終了

- ユーザインタフェースはご自由に！
- 拡張性を考慮すること
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    実は表示メッセージの先頭を言語名にしたほうが現実的な気も・・・
*/
vector<string> ja = {"おはよう", "こんにちは", "こんばんは", "さようなら"};
vector<string> en = {"Good moring", "Hello", "Good evening", "Good-by"};
vector<string> fr = {"Bonjour", "Bonjour", "Bonsoir", "Au revoir"};
vector<string> gr = {"Guten Morgen", "Guten Tag", "Guten Abend", "Auf Wiedersehen"};

vector<vector<string>> message = {ja, en, fr, gr};
vector<string> languages = {"日本語", "English", "Français", "Deutsch"};

/*
    vector<string>って参照になってる？
*/
int get_id(string title, vector<string>& disp) {
    for (;;) {
        cout << "select " << title << endl;
        for (int i = 0; i < disp.size(); i++) {
            cout << disp[i] << " = " << i + 1 << ", ";
        }
        cout << "end = 9 : ";
        string s;
        getline(cin, s);
        int id = stoi(s);
        if (id > 0 && id <= disp.size()) {
            return id;
        } else if (id == 9) {
            return id;
        }
    }
}

int main() {
    for (;;) {
        int language_id = get_id("language", languages);
        if (language_id == 9) break;
        vector<string>& my_message = message[language_id - 1];
        int message_id = get_id("message", my_message);
        if (message_id == 9) break;
        cout << my_message[message_id - 1] << endl;
    }
}