#pragma once
#include <vector>

/* Simple dynamic programming 
class Solution23 {
public:
	int numDistinct(string s, string t) {
		int slen = s.size(), tlen = t.size();
		if (slen < tlen)
			return 0;
		if (slen == 0 || tlen == 0)
			return 0;
		vector<vector<long>> matchRec(slen + 1, vector<long>(tlen + 1, 0));
		matchRec[0][0] = 1;
		for (int j = 1; j < tlen + 1; ++j) {
			matchRec[0][j] = 0;
		}
		for (int i = 1; i < slen + 1; ++i) {
			matchRec[i][0] = 1;
			for (int j = 1; j < tlen + 1; ++j) {
				matchRec[i][j] = matchRec[i - 1][j - 1] * (s[i - 1] == t[j - 1])
					+ matchRec[i - 1][j];
			}
		}
		return matchRec[slen][tlen];
	}
};
*/

/* a more insteresting method */
class Solution23 {
public:
	int numDistinct(string s, string t) {
		int slen = s.size(), tlen = t.size();
		vector<unsigned int> matchRec(tlen + 1, 0);
		matchRec[0] = 1;
		for (int i = 1; i < slen + 1; ++i) {
			for (int j = min(i, tlen); j > 0; --j) {
				if (s[i - 1] == t[j - 1]) {
					matchRec[j] += matchRec[j - 1];
				}
			}
		}
		return matchRec[tlen];
	}
};
