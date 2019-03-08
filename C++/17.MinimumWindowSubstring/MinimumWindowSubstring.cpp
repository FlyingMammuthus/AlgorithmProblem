#pragma once
#include <unordered_map>
#include <string>
#include <queue>

/*
class Solution17 {
public:
	string minWindow(string s, string t) {
		int slen = s.size(), tlen = t.size();
		if (slen < tlen || slen == 0 || tlen == 0)
			return string("");
		unordered_map<char, int> tRec;
		for (int i = 0; i < tlen; ++i) {
			auto iter = tRec.find(t[i]);
			if (iter != tRec.end())
				++(iter->second);
			else
				tRec.insert(pair<char, int>(t[i], 1));
		}
		queue<int> matchRec;
		int tCounter = tlen, retStart = 0, retEnd = slen;
		for (int i = 0; i < slen; ++i) {
			auto iter = tRec.find(s[i]);
			if (iter != tRec.end()) {
				--(iter->second);
				matchRec.push(i);
				if (iter->second >= 0){
					if (--tCounter == 0 && matchRec.back() - matchRec.front() < retEnd - retStart) {
						retStart = matchRec.front();
						retEnd = matchRec.back();
					}
				}
				else {
					while ((iter = tRec.find(s[matchRec.front()]))->second < 0) {
						matchRec.pop();
						++(iter->second);
					}
					if (tCounter == 0 && matchRec.back() - matchRec.front() < retEnd - retStart) {
						retStart = matchRec.front();
						retEnd = matchRec.back();
					}
				}
			}
		}
		if (retEnd == slen) {
			return string("");
		}
		else {
			return string(s, retStart, retEnd - retStart + 1);
		}
	}
};
*/

// considering it is map's key is char, use vector is better 
// also easily change the procedure sequence can help simplify code
class Solution17 {
public:
	string minWindow(string s, string t) {
		int slen = s.size(), tlen = t.size();
		if (slen < tlen || slen == 0 || tlen == 0)
			return string("");
		vector<int> tRec(128, 0);
		vector<bool> tExist(128, 0);
		for (auto i: t) {
			++tRec[i];
			tExist[i] = true;
		}
		queue<int> matchRec;
		int tCounter = tlen, retStart = 0, retEnd = slen;
		for (int i = 0; i < slen; ++i) {
			if (tExist[s[i]]) {
				matchRec.push(i);
				if (--tRec[s[i]] >= 0)
					--tCounter;
				while (tRec[s[matchRec.front()]] < 0) {		
					++tRec[s[matchRec.front()]];
					matchRec.pop();
				}
				if (tCounter == 0 && matchRec.back() - matchRec.front() < retEnd - retStart) {
					retStart = matchRec.front();
					retEnd = matchRec.back();
				}
			}
		}
		if (retEnd == slen) {
			return string("");
		}
		else {
			return string(s, retStart, retEnd - retStart + 1);
		}
	}
};

/* for short string, save memory
class Solution16 {
public:
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		for (auto c : t) map[c]++;
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end<s.size()) {
			if (map[s[end++]]-->0) counter--; //in t
			while (counter == 0) { //valid
				if (end - begin<d)  d = end - (head = begin);
				if (map[s[begin++]]++ == 0) counter++;  //make it invalid
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};
*/
