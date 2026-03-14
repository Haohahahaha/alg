#include <bits/stdc++.h>
using namespace std;

// 计算所有两两乘积之和：sum_{i<j} a[i]*a[j]
// O(n)，避免 O(n^2) 超时，使用 64 位防止溢出
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long prefix_sum = 0;   // 已读元素之和
    long long ans = 0;          // 结果

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        ans += prefix_sum * x;  // 当前数与之前所有数相乘
        prefix_sum += x;
    }

    cout << ans << "\n";
    return 0;
}