// 将以下内容保存到 3-alg/docs/hz333/code/luogu-b3726.cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    // 启用高速I/O（非常重要，可大幅减少读取时间）
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> firstOccurrence; // 字符串 -> 首次出现的行号（1开始）
    vector<string> nonShadows;

    string s;
    int lineNum = 0;

    // 读入每一行，直到遇到 "0"
    while (true) {
        getline(cin, s);
        lineNum++;  // 下一行的行号

        // 结束条件：题目说明输入结尾为一行仅含 "0"
        if (s == "0") {
            break;
        }

        // 如果该字符串是第一次出现
        if (firstOccurrence.find(s) == firstOccurrence.end()) {
            firstOccurrence[s] = lineNum;
        }

        // 判断是否为“影子”：当前行号 > 首次出现的行号 → 跳过
        if (lineNum > firstOccurrence[s]) {
            continue;
        } else {
            nonShadows.push_back(s);
        }
    }

    // 拼接非影子字符串（空格分隔）
    for (size_t i = 0; i < nonShadows.size(); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << nonShadows[i];
    }
    cout << "\n"; // 输出一个换行

    return 0;
}