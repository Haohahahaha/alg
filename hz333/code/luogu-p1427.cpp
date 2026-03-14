#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){

    string line;
    getline(cin, line);     // 只读取一行
    string str[120];        // 设置单词数组
    
    stringstream ss(line);  // 分隔每个单词
    
    int i = 0;
    while(ss >> str[i]) {
        i++;
    }

    for(int j = i - 2; j >= 0; j--) {
        cout << str[j];
        if (j != 0) cout << " ";
    }
    cout << endl;


    return 0;
}