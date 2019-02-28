#pragma once
#include <string>
#include <vector>
using namespace std;

// dynamic programming
/*
class Solution10 {
public:
	bool isMatch(string s, string p) {
		int sLen = s.size(), pLen = p.size();
		vector<vector<bool>> matchRec(sLen + 1, vector<bool>(pLen + 1, false));  // Caution: vector size
		matchRec[0][0] = true;
		for (int j = 0; j < pLen; ++j) {
			matchRec[0][j + 1] = p[j] == '*' && matchRec[0][j];
		}
		for (int i = 0; i < sLen; ++i) {
			for (int j = 0; j < pLen; ++j) {
				if (p[j] == '?' || s[i] == p[j]) {
					matchRec[i + 1][j + 1] = matchRec[i][j];
				}
				else if (p[j] == '*') {
					matchRec[i + 1][j + 1] = matchRec[i + 1][j] || matchRec[i][j + 1]; // important!!!
				}
			}
		}
		return matchRec[sLen][pLen];
	}
};
*/

/*
bool isMatch(string s, string p) {
int sLen = s.size(), pLen = p.size(), sPre = 0, pPre = 0, sRec = pLen, pRec = sLen;
while (sPre < sLen) {
if (s[sPre] == p[pPre] || p[pPre] == '?') {
++sPre;
++pPre;
} else if (p[pPre] == '*') {
pRec = pPre++;
sRec = sPre;
} else if (pRec < sLen) {
pPre = pRec + 1;
sPre = ++sRec;
} else return false;
}
while (p[pPre] == '*') ++pPre;
return pPre == pLen - 1;
}
*/

// using two pointers
class Solution10 {
public:
	bool isMatch(string s, string p) {
		char *scur = &s[0], *pcur = &p[0], *sstar = NULL, *pstar = NULL;
		while (*scur) {
			if (*scur == *pcur || *pcur == '?') {
				++scur;
				++pcur;
			}
			else if (*pcur == '*') {
				pstar = pcur++;
				sstar = scur;
			}
			else if (pstar) {
				pcur = pstar + 1;
				scur = ++sstar;
			}
			else return false;
		}
		while (*pcur == '*') ++pcur;
		return !*pcur;
	}
};
