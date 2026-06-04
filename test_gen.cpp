#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstring>
using namespace std;

const int N = 100000;    
const int N_str = 10000;

// Hàm sinh chuỗi ngẫu nhiên đảm bảo độ dài từ 10 đến 100
string randomString(int minLen, int maxLen) {
    int len = minLen + rand() % (maxLen - minLen + 1);
    string s = "";
    for (int i = 0; i < len; ++i) {
        s += (char)('a' + rand() % 26); // Chỉ gồm ký tự 'a'-'z'
    }
    return s;
}

// Các hàm lưu file
void saveIntTest(const string& filename, const vector<int>& arr) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << arr.size() << "\n";
        for (int x : arr) outFile << x << "\n";
        outFile.close();
        cout << "Da tao: " << filename << endl;
    }
}

void saveStrTest(string filename, const vector<string>& data) {
    ofstream f("strlexi/" + filename);
    if (f.is_open()) {
        f << data.size() << "\n";
        for (const string& s : data) f << s << "\n";
        f.close();
        cout << "Da tao: strlexi/" << filename << endl;
    }
}

void saveStrLenTest(string filename, const vector<string>& data) {
    ofstream f("strlenlexi/" + filename);
    if (f.is_open()) {
        f << data.size() << "\n";
        for (const string& s : data) f << s << "\n";
        f.close();
        cout << "Da tao: strlenlexi/" << filename << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
    cerr << "Loi!\n";
    cerr << "Cach dung: " << argv[0] << " <ten_file> <int/strlexi/strlenlexi> <1/2/3/4/5>\n";
    return 1;
    }
    srand(time(0));
    if(strcmp(argv[1], "int") == 0){
    vector<int> data_int(N);
    int tmp = atoi(argv[2]);
    switch(tmp){
    case 1:
    // Test 001: Mảng giảm dần
        for (int i = 0; i < N; ++i) data_int[i] = N - i; break;
    case 2:
    // Test 002: Mảng tăng dần
        for (int i = 0; i < N; ++i) data_int[i] = i + 1; break;
    case 3:
    // Test 003: Mảng chứa toàn bộ số giống nhau
        fill(data_int.begin(), data_int.end(), 24120410); break;
    case 4:
    // Test 004: Mảng ngẫu nhiên (Dải 32-bit signed)
        for (int i = 0; i < N; ++i) data_int[i] = (rand() * rand()) % 2000001 - 1000000; break;
    case 5:
    // Test 005: Mảng hình răng cưa (Sawtooth)
        for (int i = 0; i < N; ++i) {
            if (i % 2 == 0) data_int[i] = i;
            else data_int[i] = N - i;
        }
        break;
    }
}
    else if(strcmp(argv[1], "strlexi") == 0){
    vector<string> data_str(N);
    int tmp = atoi(argv[2]);
    switch(tmp){
    case 1:
    // Test 001: Ngẫu nhiên hoàn toàn
    for (int i = 0; i < N; ++i) data_str[i] = randomString(10, 100);
    break;
    case 2:
    // Test 002: Chuỗi giảm dần theo từ điển
    for (int i = 0; i < N; ++i) data_str[i] = randomString(10, 10);
    sort(data_str.rbegin(), data_str.rend());
    break;
    case 3: {
    // Test 003: Tiền tố giống hệt nhau cực dài (Sửa lại 90 ký tự để tổng < 100)
        string prefix(90, 'a');
        for (int i = 0; i < N; ++i) data_str[i] = prefix + (char)('a' + (i % 26));
        break;
    }
    case 4: {
    // Test 004: Toàn bộ chuỗi giống hệt nhau
        string same = "thisisasamestringlengthten"; // Độ dài > 10
        fill(data_str.begin(), data_str.end(), same);
        break;
    }
    case 5:
    // Test 005: Chuỗi tăng dần
    for (int i = 0; i < N; ++i) data_str[i] = randomString(12, 12);
    sort(data_str.begin(), data_str.end());
    break;
    }
}
    else if(strcmp(argv[1], "strlenlexi") == 0){
    vector<string> data(N_str);
    int tmp = atoi(argv[2]);
    switch(tmp){
    case 1:
    // Test 001: Độ dài giảm dần (từ 100 xuống 10)
    for (int i = 0; i < N_str; ++i) {
        int l = 100 - (i % 91); 
        data[i] = string(l, 'a');
    }
    break;
    case 2:
    // Test 002: Độ dài tăng dần (từ 10 lên 100)
    for (int i = 0; i < N_str; ++i) {
        int l = 10 + (i % 91);
        data[i] = string(l, 'b');
    }
    break;
    case 3:
    // Test 003: Cùng độ dài nhưng thứ tự từ điển ngược (Sửa số 0 thành chữ cái)
    for (int i = 0; i < N_str; ++i) {
        data[i] = randomString(50, 50);
    }
    sort(data.rbegin(), data.rend());
    break;
    case 4: {
    // Test 004: Tiền tố giống nhau và cùng độ dài
    string longprefix(95, 'm');
    for (int i = 0; i < N_str; ++i) {
        data[i] = longprefix + (char)('a' + (i % 26));
    }
    break;
    }
    case 5:
    // Test 005: Ngẫu nhiên hoàn toàn
    for (int i = 0; i < N_str; ++i) {
        data[i] = randomString(10, 100);
    }
    break;
}
}

    return 0;
}