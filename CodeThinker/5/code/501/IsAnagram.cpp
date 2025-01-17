/* LeetCode Question No.242
 * Given two strings s and t, return true if t is an anagram of s, and false 
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a 
 * different word or phrase, typically using all the original letters exactly
 * once.
 */

#include "IsAnagram.h"

bool IsAnagram::isAnagram(std::string s, std::string t) {
	int record[26] = {0};

	for (int i = 0; i < s.size(); i++) {
		record[s[i] - 'a']++;
	}

	for (int i = 0; i < t.size(); i++) {
		record[t[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++) { 
		if (record[i] != 0) {
			return false;
		}
	}
	return true;
}

