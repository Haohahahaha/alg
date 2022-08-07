#include <iostream>
#include "IsAnagram.h"

using namespace std;

int main() {
	IsAnagram judge;
	string s = "abc";
	string t = "cba";
	cout << judge.isAnagram(s, t);
	return 0;
}
