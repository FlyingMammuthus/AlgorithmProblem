#pragma once
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>

using namespace std;
// one easy way is to use map
/*
class Solution5 {
public:
	typedef map<string, pair<int, int>> wordsRecorder;
	static vector<int> findSubstring(string s, vector<string>& words) {
		int sSize = s.size();	
		vector<int> ret;
		if (words.empty()) {           // return []
			return ret;
		}
		int wLen = words[0].size(), wNum = words.size(), sPre = 0;
		wordsRecorder wRec;
		wordsRecorder::iterator iter;
		for (auto word : words) {
			iter = wRec.find(word);
			if (iter == wRec.end()) {
				wRec.insert(wordsRecorder::value_type(word, pair<int, int>(0, 1)));
			}
			else {
				++((iter->second).second);
			}
		}
		int count = 0;
		stack<wordsRecorder::iterator> iterRec;
		while (sPre <= sSize - wLen * wNum) {                           //Caution s.size() is unsigned int so use sSize instead of s.size(), or will lead to error ('while' will not stop)
			count = 0;
			ret.push_back(sPre);
			while (count < wNum) {                
				iter = wRec.find(s.substr(sPre, wLen));//the second argment of substr() is length, not endPos.
				if (iter == wRec.end() || (iter->second).second <= (iter->second).first) {
					break;
				}
				++count;
				if ((iter->second).first == 0){
					iterRec.push(iter);
				}
				++((iter->second).first);
				sPre += wLen;
			}
			sPre = ret.back() + 1;
			if (count != wNum) {
				ret.pop_back();
			}
			while (!iterRec.empty()) {
				iter = iterRec.top();
				(iter->second).first = 0;
				iterRec.pop();
			}
		}
		return ret;
	}
};
*/

// using unordered_map (hash table) or use two map instead of one
class Solution5 {
public:
	typedef unordered_map<string, pair<int, int>> wordsRecorder;
	static vector<int> findSubstring(string s, vector<string>& words) {
		int sSize = s.size();
		vector<int> ret;
		if (words.empty()) {           // return []
			return ret;
		}
		int wLen = words[0].size(), wNum = words.size(), sPre = 0;
		wordsRecorder wRec;
		wordsRecorder::iterator iter;
		for (auto word : words) {
			iter = wRec.find(word);
			if (iter == wRec.end()) {
				wRec.insert(wordsRecorder::value_type(word, pair<int, int>(0, 1)));
			}
			else {
				++((iter->second).second);
			}
		}
		int count = 0;
		stack<wordsRecorder::iterator> iterRec;
		while (sPre <= sSize - wLen * wNum) {                           //Caution s.size() is unsigned int so use sSize instead of s.size(), or will lead to error ('while' will not stop)
			count = 0;
			ret.push_back(sPre);
			while (count < wNum) {                  
				iter = wRec.find(s.substr(sPre, wLen));//the second argment of substr() is length, not endPos.
				if (iter == wRec.end() || (iter->second).second <= (iter->second).first) {
					break;
				}
				++count;
				if ((iter->second).first == 0) {
					iterRec.push(iter);
				}
				++((iter->second).first);
				sPre += wLen;
			}
			sPre = ret.back() + 1;
			if (count != wNum) {
				ret.pop_back();
			}
			while (!iterRec.empty()) {
				iter = iterRec.top();
				(iter->second).first = 0;
				iterRec.pop();
			}
		}
		return ret;
	}
};
/* one fast version from others 
class Solution {
public:
vector<int> findSubstring(string s, vector<string>& words) {
if (words.empty()) {
return vector<int>();
}
unordered_map<string, int> targets;
for (const string &word : words) {
targets[word]++;
}
const int len = words[0].size();
const int n = s.size();
unordered_map<string, int> cnts;
vector<int> results;
for (int i = 0; i < len; ++i) {
cnts.clear();
for (int j = i, k = i; k + len <= n; k += len) {
const string word = s.substr(k, len);
if (targets.count(word) == 0) {
cnts.clear();
j = k + len;
} else {
if (++cnts[word] > targets[word]) {
while (cnts[word] > targets[word]) {
--cnts[s.substr(j, len)];
j += len;
}
}
if ((k - j) / len + 1 == words.size()) {
results.push_back(j);
}
}
}
}
return results;
}
};
*/
