#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

/* basic idea: dynamic programming
class Solution16 {
public:
	int minDistance(string word1, string word2) {
		int size1 = word1.size(), size2 = word2.size();
		if (size1 == 0)
			return size2;
		if (size2 == 0)
			return size1;

		vector<vector<int>> disRec(size1 + 1, vector<int>(size2 + 1, 0));
		for (int i = 0; i < size1 + 1; ++i) {
			disRec[i][0] = i;
		}
		for (int j = 1; j < size2 + 1; ++j) {
			disRec[0][j] = j;
			for (int i = 1; i < size1 + 1; ++i) {
				disRec[i][j] = min(min(disRec[i][j - 1], disRec[i - 1][j]) + 1, 
					disRec[i - 1][j - 1] + (word1[i-1] != word2[j-1]));
			}
		}
		return disRec[size1][size2];
	}
};
*/

/*
// Save memory method
class Solution16 {
public:
	int minDistance(string word1, string word2) {
		int size1 = word1.size(), size2 = word2.size();
		if (size1 == 0)
			return size2;
		if (size2 == 0)
			return size1;

		vector<int> prev(size1 + 1, 0), next(size1 + 1, 0);
		for (int i = 0; i < size1 + 1; ++i) {
			prev[i] = i;
		}
		for (int j = 1; j < size2 + 1; ++j) {
			next[0] = j;
			for (int i = 1; i < size1 + 1; ++i) {
				next[i] = min(prev[i - 1] + (word1[i - 1] != word2[j - 1]),
					min(prev[i], next[i - 1]) + 1);
			}
			prev.swap(next);
		}
		return prev[size1];
	}
};
*/

// judge size1 and size2
class Solution16 {
public:
	int minDistance(string word1, string word2) {
		int size1 = word1.size(), size2 = word2.size();
		if (size1 == 0)
			return size2;
		if (size2 == 0)
			return size1;

		/* WRONG
		string &str1 = word1, &str2 = word2;

		if (size1 > size2) {
			str1 = word2;    // error, will change word1 into word2.
			str2 = word1;
			size1 = word2.size();
			size2 = word1.size();
		}
		*/

		string *str1 = &word1, *str2 = &word2;

		if (size1 < size2) {
			str1 = &word2;
			str2 = &word1;
			size1 = word2.size();
			size2 = word1.size();
		}

		vector<int> prev(size1 + 1, 0), next(size1 + 1, 0);
		for (int i = 0; i < size1 + 1; ++i) {
			prev[i] = i;
		}
		for (int j = 1; j < size2 + 1; ++j) {
			next[0] = j;
			for (int i = 1; i < size1 + 1; ++i) {
				next[i] = min(prev[i - 1] + ((*str1)[i - 1] != (*str2)[j - 1]),
					min(prev[i], next[i - 1]) + 1);
			}
			prev.swap(next);
		}
		return prev[size1];
	}
};
