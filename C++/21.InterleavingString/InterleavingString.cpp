#pragma once

/* one basic solution : recurssion
class Solution21 {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		return stringleave(s1, s2, s3, 0, 0);
	}

	bool stringleave(string &s1, string &s2, string &s3, int l1, int l2) {
		int l3 = l1 + l2;
		if (l1 == s1.size()) {
			return s2.substr(l2, s2.size() - l2) == s3.substr(l3, s2.size() - l2);
		}
		if (l2 == s2.size()) {
			return s1.substr(l1, s1.size() - l1) == s3.substr(l3, s1.size() - l1);
		}

		return (s3[l3] == s1[l1] && stringleave(s1, s2, s3, l1 + 1, l2))
			|| (s3[l3] == s2[l2] && stringleave(s1, s2, s3, l1, l2 + 1));
	}
};
*/

class Solution21 {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		int slen1 = s1.size(), slen2 = s2.size();
		if (slen1 == 0) {
			return s2 == s3;
		}
		if (slen2 == 0) {
			return s1 == s3;
		}
		vector<vector<bool>> isRec(slen1 + 1, vector<bool>(slen2 + 1, false));
		isRec[0][0] = true;
		for (int j = 1; j < slen2 + 1; ++j) { 
			isRec[0][j] = isRec[0][j - 1] && (s2[j - 1] == s3[j - 1]); /* Don't use: isRec[0][j] = s2.substr(0, j) == s3.substr(0, j); */
		}
		for (int i = 1; i < slen1 + 1; ++i) {
			isRec[i][0] = isRec[i - 1][0] && (s1[i - 1] == s3[i - 1]); /* Don't use: isRec[i][0] = s1.substr(0, i) == s3.substr(0, i); */
			for (int j = 1; j < slen2 + 1; ++j) {
				isRec[i][j] = (isRec[i][j - 1] && (s2[j - 1] == s3[i + j - 1]))
					|| (isRec[i - 1][j] && (s1[i - 1] == s3[i + j - 1]));
			}
		}
		return isRec[slen1][slen2];
	}
};
