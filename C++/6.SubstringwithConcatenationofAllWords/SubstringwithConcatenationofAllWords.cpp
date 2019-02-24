#pragma once
#include <string>

using namespace std;
class Solution6 {
public:
	static int longestValidParentheses(string s) {
		int endPre = 0, maxLen = 0, sLen = s.size(), leftCount = 0, rightCount = 0, lenPre = 0; // define sLen of type int
		while (endPre < sLen) {
			if (s[endPre++] == '(') {
				++leftCount;
			}
			else if (rightCount++ < leftCount);
			else {
				lenPre = leftCount << 1; // Why not use rightCount + leftCount? consider ")()()(" 
				if (maxLen < lenPre) {
					maxLen = lenPre;
				}
				rightCount = 0;
				leftCount = 0;           // Caution: no need to adjust head of this substr, no possibility of moving head and making rightCount == leftCount
			}
		}
		if (leftCount > rightCount) {    // search last part of substr reversely (ex. "()(()")
			int start = sLen - leftCount - rightCount;
			endPre = sLen - 1;
			leftCount = 0;
			rightCount = 0;
			while (endPre >= start) {
				if (s[endPre--] == ')') {
					++rightCount;
				}
				else if (leftCount++ < rightCount);
				else {
					lenPre = rightCount << 1; 
					if (maxLen < lenPre) {
						maxLen = lenPre;
					}
					rightCount = 0;
					leftCount = 0;          
				}
			}
		}
		lenPre = leftCount << 1;
		if (maxLen < lenPre) {
			maxLen = lenPre;
		}

		return maxLen;
	}
};
