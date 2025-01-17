#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {

    string sentence; // 输入的整行句子
    getline(cin, sentence); // 读取整行输入
    string words[1000]; // 存储单词
    int wordCount = 0; // 记录单词数量

    string currentWord = ""; // 临时存储当前单词

    // 遍历输入字符串
    for (char ch : sentence) {
        if (ch != ' ') {
            currentWord += ch; // 累积当前单词
        } else {
            if (!currentWord.empty()) { // 当前单词结束
                words[wordCount++] = currentWord;
                currentWord = ""; // 清空临时单词
            }
        }
    }
    // 最后一个单词加入数组
    if (!currentWord.empty()) {
        words[wordCount++] = currentWord;
    }

    // 处理单词
    for (int i = 0; i < wordCount; i++) {
        string &word = words[i];
        if (islower(word[0])) { // 全小写 -> 全大写
            for (char &c : word) {
                c = toupper(c);
            }
        } else if (isupper(word[0])) { // 全大写 -> 全小写
            for (char &c : word) {
                c = tolower(c);
            }
        } else if (isdigit(word[0])) { // 数字 -> 翻转
            int len = word.length();
            for (int j = 0; j < len / 2; j++) {
                // 交换左右对称字符
                swap(word[j], word[len - 1 - j]);
            }
        }
    }

    // 倒序输出单词
    for (int i = wordCount - 1; i >= 0; i--) {
        cout << words[i];
        if (i > 0) {
            cout << ' ';
        }
    }
    cout << endl; // 输出换行


    return 0;
}