#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string line;
    getline(cin, line);     // 只读取一行

    string str[1020];
    int i = 0;

    stringstream ss(line);  // 分隔每个单词
    while (ss >> str[i]) {
        i++;
    }

    // 倒序处理
    for (int j = i - 1; j >= 0; j--) {
        // 判断类型 + 转换
        string w = str[j];

        // 判断是否为数字
        bool isNumber = true;
        for (char c : w) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (isNumber) {
            reverse(w.begin(), w.end());
        } else if (islower(w[0])) { // 通过首字母判断单词大小写，取巧做法。如需每个字符均取反，那应该用循环遍历。
            for (char &c : w) c = toupper(c);
        } else {
            for (char &c : w) c = tolower(c);
        }

        // 输出
        cout << w;
        if (j != 0) cout << " ";
    }
    cout << endl;
        
    return 0;
}


