#pragma once
#include <vector>
#include <algorithm>
/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

class Solution13 {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int startNum = lower_bound(intervals.begin(), intervals.end(), newInterval, compStart) - intervals.begin(),  // Using lower_bound(...) for binary search
			endNum = lower_bound(intervals.begin(), intervals.end(), newInterval, compEnd) - intervals.begin();
		int intrvlNum = intervals.size();
		vector<Interval> ret;
		for (int i = 0; i < startNum - 1; ++i) {
			ret.push_back(intervals[i]);
		}
		Interval mergeInt(newInterval);
		if (startNum > 0) {                                           // Caution : consider bound first
			if (intervals[startNum - 1].end < newInterval.start) {
				ret.push_back(intervals[startNum - 1]);
			}
			else {
				mergeInt.start = intervals[startNum - 1].start;
			}
		}

		if (endNum < intrvlNum) {                                     // Caution : consider bound first
			if (intervals[endNum].start > newInterval.end) {
				ret.push_back(mergeInt);
				ret.push_back(intervals[endNum]);
			}
			else {
				mergeInt.end = intervals[endNum].end;
				ret.push_back(mergeInt);
			}
		}
		else {
			ret.push_back(mergeInt);
		}

		for (int i = endNum + 1; i < intrvlNum; ++i) {
			ret.push_back(intervals[i]);
		}
		return ret;
	}

	static bool compStart(const Interval &int1, const Interval &int2) {
		return int1.start < int2.start;
	}

	static bool compEnd(const Interval &int1, const Interval &int2) {
		return int1.end < int2.end;
	}
};
