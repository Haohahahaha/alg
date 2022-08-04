## 2021-08011_Uva1583,Digit_Generator

![2021-08011_Uva1583,Digit_Generator](./Problem.jpg)

My Answer:

```cpp
#include <stdio.h>
#include <string.h>
#define maxn 100005
int ans[maxn];

int main() {

	int T, n;
	memset(ans, 0, sizeof(ans));
	
	for (int m = 1; m < maxn; m++) {
		int x = m, y = m;
		while (x > 0) {
			y += x % 10;
			x /= 10;
		}
		if (ans[y] == 0 || m < ans[y]) {
			ans[y] = m;
		}
	}

	scanf_s("%d", &T);
	while (T--) {
		scanf_s("%d", &n);
		printf("%d\n", ans[n]);
	}
		

	return 0;
}
```

My Notes:

This is a really simple and classical problem by using table-driven approach, it's not hard. But I learn a new function `memset()`, which can initialize each element of a huge array. And what I need to focus is that the huge array need to be defined outside the main function. It can make the main function run easier.

