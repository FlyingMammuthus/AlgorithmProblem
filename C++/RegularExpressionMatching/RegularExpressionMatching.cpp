#pragma once
#include <string>

using namespace std;
class Solution2 {
public:
	static bool isMatch(string s, string p) {
		return isMatchPart(s, p, 0, 0);
	}
	/*
	static bool isMatchPart(const string &s, const string &p, int s_index, int p_index) {
		int s_size = s.size(), p_size = p.size(), s_count;
		while (s_index < s_size && p_index < p_size) {
			if (p_index < p_size - 1 && p[p_index + 1] == '*') {
				int i = s_index;
				if (s[s_index] == p[p_index]) {
					while (s_index < s_size - 1 && s[++s_index] == p[p_index]);
					if (s_index == s_size - 1 && s[s_index] == p[p_index]) {   // Caution: don't forget this step : the two judgement is correponding to two different situations:
						++s_index;                                             // 1. s:aa p:a*    2. s:ab p:a*          
					}
				}
				else if (p[p_index] == '.') {
					s_index = s_size;
				}          // Consider why you have if/if else but no else in the end(it is unnecessary).
				for (; i <= s_index; ++i) {   // Caution: use <= instead of <
					if (isMatchPart(s, p, i, p_index + 2)) {
						return true;
					}
				}
				return false;
			}
			else if (s[s_index++] == p[p_index++] || p[p_index-1] == '.');
			else {
				return false;
			}
		}
		if (s_index >= s_size) {
			if (p_index < p_size) {
				while (p_index < p_size) {
					if (p_index >= p_size-1 || p[++p_index] != '*') {
						return false;
					}
					++p_index;
				}
			}
			return true;
		}
		return false;
	}
	*/

	//dynamic programming
	static bool isMatchPart(const string &s, const string &p, int s_index, int p_index) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;

		for (int j = 0; j < n; j++)
			dp[0][j + 1] = p[j] == '*' && dp[0][j - 1]; // caution : here is j-1

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (p[j] == '.' || p[j] == s[i])
					dp[i + 1][j + 1] = dp[i][j];
				else if (p[j] == '*') {
					dp[i + 1][j + 1] = dp[i + 1][j - 1];
					if (p[j - 1] == '.' || p[j - 1] == s[i])
						dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i][j + 1];   // this is important
				}
			}

		}
		return dp[m][n];
	}
};
