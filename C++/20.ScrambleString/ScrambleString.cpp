#pragma once
#include <vector>

/* dynamic programming. Memory is too large, switch memory will use much time
class Solution20 {
public:
	bool isScramble(string s1, string s2) {
		int slen = s1.size();
		if (slen != s2.size()) {
			return false;
		}
		if (slen == 0) {
			return true;
		}

		vector<vector<vector<bool>>> match(slen, vector<vector<bool>>(slen, vector<bool>(slen, false)));
		for (int m = 0; m < slen; ++m) {
			for (int n = 0; n < slen; ++n) {
				match[0][m][n] = s1[m] == s2[n];
			}
		}

		for (int len = 1; len < slen; ++len) {
			for (int m = 0; m < slen - len; ++m) {
				for (int n = 0; n < slen - len; ++n) {
					for (int p = 0; p < len; ++p) {
						match[len][m][n] = (match[p][m][n] && match[len - p - 1][m + p + 1][n + p + 1]) || match[len][m][n];
						match[len][m][n] = (match[p][m][n + len - p] && match[len - p - 1][m + p + 1][n]) || match[len][m][n];
					}
				}
			}
		}
		return match[slen - 1][0][0];
	}
};
*/

// simple recurssion will be quicker, but check the wrong situation first. Or it may lead to much much more time.
class Solution20 {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		int len = s1.length();
		int count[26] = { 0 };
		for (int i = 0; i<len; i++)
		{
			count[s1[i] - 'a']++;
			count[s2[i] - 'a']--;
		}

		for (int i = 0; i<26; i++)
		{
			if (count[i] != 0)
				return false;
		}

		for (int i = 1; i <= len - 1; i++)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
				return true;
		}
		return false;
	}
};
