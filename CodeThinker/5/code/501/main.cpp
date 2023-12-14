#include "IsAnagram.h"

using namespace std;

int main() {
	IsAnagram judge;
	string s = "abc";
	string t = "cba";
	if (judge.isAnagram(s, t)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}
