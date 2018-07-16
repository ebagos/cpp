#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<double> data {
    148.7, 149.5, 133.7, 157.9, 154.2, 147.8, 154.6, 159.1, 148.2, 153.1,
    138.2, 138.7, 143.5, 153.2, 150.2, 157.3, 145.1, 157.2, 152.3, 148.3,
    152.0, 146.0, 151.5, 139.4, 158.8, 147.6, 144.0, 145.8, 155.4, 155.5,
    153.6, 138.5, 147.1, 149.6, 160.9, 148.9, 157.5, 155.1, 138.9, 153.0,
    153.9, 150.9, 144.4, 160.3, 153.4, 163.0, 150.9, 153.3, 146.6, 153.3,
    152.3, 153.3, 142.8, 149.0, 149.4, 156.5, 141.7, 146.2, 151.0, 156.5,
    150.8, 141.0, 149.0, 163.2, 144.1, 147.1, 167.9, 155.3, 142.9, 148.7,
    164.8, 154.1, 150.4, 154.2, 161.4, 155.0, 146.8, 154.2, 152.7, 149.7,
    151.5, 154.5, 156.8, 150.3, 143.2, 149.5, 145.6, 140.4, 136.5, 146.9,
    158.9, 144.4, 148.1, 155.5, 152.4, 153.3, 142.3, 155.3, 153.1, 152.3
};

void fdisp(double min, double max, int count) {
    cout << min << "cm - " << max << "cm : " << count << endl;
}

int main(int argc, char **argv) {
    double min = 130.0;
    double max;
    // copy_ifをフィルタとして利用
    while (min < 170.0) {
        vector<double> a;
        max = min + 5.0;
        copy_if(data.begin(),
                data.end(),
                back_inserter(a),
                [min, max](double x) {return ((x > min) && (x <= max));});
        fdisp(min, max, a.size());
        min = max;
    }
    cout << endl;

    // いちいちフィルタされたvectorを作るのはもったいないのでcount_ifを使用
    min = 130.0;
    while (min < 170.0) {
        max = min + 5.0;
        int count = count_if(data.begin(), 
                    data.end(),
                    [min, max](double x) {return ((x > min) && (x <= max));});
        fdisp(min, max, count);
        min = max;
    }
    cout << endl;

    /*
       実際はデータすべてを格納してから処理するなんてありえないから・・・
    */
    int freq[10] = {0};
    for (int i = 0; i < data.size(); i++) {
        if (data[i] <= 130.0) {freq[0]++;}
        else if (data[i] > 130.0 && data[i] <= 135.0) {freq[1]++;}
        else if (data[i] > 135.0 && data[i] <= 140.0) {freq[2]++;}
        else if (data[i] > 140.0 && data[i] <= 145.0) {freq[3]++;}
        else if (data[i] > 145.0 && data[i] <= 150.0) {freq[4]++;}
        else if (data[i] > 150.0 && data[i] <= 155.0) {freq[5]++;}
        else if (data[i] > 155.0 && data[i] <= 160.0) {freq[6]++;}
        else if (data[i] > 160.0 && data[i] <= 167.0) {freq[7]++;}
        else if (data[i] > 165.0 && data[i] <= 170.0) {freq[8]++;}
        else {freq[9]++;}
    }
    for (int i = 1; i < 9; i++) {
        cout << 125+i*5 << "cm - " << 130+i*5 << "cm : " << freq[i] << endl;
    }
    cout << endl;
    //  しかし、分類する条件がもっと多かったらif-elseじゃ無理
    
    struct Sum {
        Sum() {sum = 0.0;}
        void operator()(double x) {sum += x;} 

        double sum;
    };
    Sum s = for_each(data.begin(), data.end(), Sum());
    cout << "sum = " << s.sum << endl;
    cout << "average = " << s.sum / (double)data.size() << endl;
}