#pragma once
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution15 {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ret;
		string strline(maxWidth, ' ');
		int wNum = words.size(), wPre = 0;
		while (wPre < wNum) {
			int wBef = wPre, ccnt = -1;
			while (ccnt < maxWidth && wPre < wNum) {
				ccnt += words[wPre++].size() + 1;
			}
			if (ccnt > maxWidth) {
				ccnt -= words[--wPre].size() + 1;
			}
			int wcnt = wPre - wBef;
			int cIntv = (maxWidth - ccnt) / (wcnt>1 ? wcnt - 1 : wcnt) + (wcnt>1 ? 1 : 0);
			int wDiv = (maxWidth - ccnt) % (wcnt>1 ? wcnt - 1 : wcnt) + wBef;
			if (wPre == wNum) {
				fill(strline.begin(), strline.end(), ' ');
				cIntv = 1;
				wDiv = 0;
			}
			string insrtInter(cIntv, ' ');
			for (ccnt = 0; wBef < wDiv; ++wBef) {
				strline.replace(ccnt, words[wBef].size(), words[wBef]);
				ccnt += words[wBef].size();
				strline.replace(ccnt, insrtInter.size(), insrtInter);
				ccnt += cIntv;
				strline.replace(ccnt, 1, " ");
				++ccnt;
			}
			for (; wBef < wPre - 1; ++wBef) {
				strline.replace(ccnt, words[wBef].size(), words[wBef]);
				ccnt += words[wBef].size();
				strline.replace(ccnt, insrtInter.size(), insrtInter);
				ccnt += cIntv;
			}
			strline.replace(ccnt, words[wBef].size(), words[wBef]);
			ccnt += words[wBef].size();
			if (wcnt == 1 && ccnt < maxWidth - 1) {          // ccnt < maxWidth-1 : {"a"}, 1 
				strline.replace(ccnt, insrtInter.size(), insrtInter);
			}
			++wBef;
			ret.push_back(strline);
		}
		return ret;
	}
};
