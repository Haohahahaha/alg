2021-08-04_Uva272,Tex_Quotes

![2021-08-04_Uva272,Tex_Quotes_1](./Problem_1.jpg)

![2021-08-04_Uva272,Tex_Quotes_2](./Problem_2.jpg)

My problem-thinking idea:

![My_idea](My_idea.png)

My Answer:

```cpp
#include<iostream>
using namespace std;
int main() {
	int c, q = 1;
	while ((c = getchar()) != EOF) {
		if (c == '"') {
			printf("%s", q ? "``" : "''"); 
			q = !q;
		}
		else
		{
			printf("%c", c);
		} 
	}
	return 0;
}
```

