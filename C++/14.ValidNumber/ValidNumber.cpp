#pragma once
#include <string>

using std::string;
class Solution14 {
public:
	/*
	bool isNumber(string s) {
		int sLen = s.size(), sPre = 0, isDec = -1, isExp = -1;
		while (sPre < sLen && s[sPre] == ' ') {  // for input like "   1"
			++sPre;
		}
		if (sPre == sLen) {  // for input like "    " 
			return false;
		}
		char cPre = s[sPre];
		if (sPre < sLen && (cPre < '0' || cPre > '9')) {  // for input like "e1234"
			if (cPre == '.') {
				isDec = true;
				++sPre;
				if (sPre == sLen || s[sPre] < '0' || s[sPre] > '9') {
					return false;
				}
			}
			else
				return false;
		}
		++sPre;
		while (sPre < sLen) {
			cPre = s[sPre];
			if (s[sPre] < '0' || s[sPre] > '9') {
				if (s[sPre] == '.' && isDec == -1 && isExp == -1) {
					isDec = sPre;
				}
				else if (s[sPre] == 'e' && isExp == -1) {
					isExp = sPre;
				}
				else {
					break;
				}
			}
			++sPre;
		}
		if (isExp > -1 && (isExp == sLen-1 || s[isExp + 1] < '0' || s[isExp + 1] > '9')) {
			return false;
		}
		if (sPre < sLen) {
			while (sPre < sLen && s[sPre++] == ' ');   // for input like "1   "
			return sPre == sLen && s[sLen-1] == ' ';  // "s[sLen-1] == ' ' " is for input like "1 4"
		}
		else if (isExp && s[sLen-1] == 'e') {  // for input like "1234e"
			return false;
		}
		return true;
	}
	*/
}
