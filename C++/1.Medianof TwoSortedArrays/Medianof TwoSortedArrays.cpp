#pragma once
#include <vector>

using namespace std;
/*
class Solution {
public:
	static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> *p1, *p2;
		int totSize = nums1.size() + nums2.size();
		int halfSize = totSize >> 1;
		bool isAver = (totSize == (halfSize << 1));
		if (nums1.size() <= nums2.size()) {
			p1 = &nums1;
			p2 = &nums2;
		}
		else {
			p1 = &nums2;
			p2 = &nums1;
		}
		if (p1->size() == 0) {
			return isAver ? ((*p2)[halfSize - 1] + (*p2)[halfSize]) / 2.0 : (*p2)[halfSize];
		}
		int size1 = p1->size(), start1 = 0, end1 = size1,
			div1 = (start1 + end1) >> 1, div2 = halfSize - div1; // div is a division mark which is not included in the left part

		int max_left, min_right;
		while (div1 != start1) {               // consider limitations. The judgment is important. Consider why it is like this.
			if ((*p1)[div1 - 1] <= (*p2)[div2] && (*p2)[div2 - 1] <= (*p1)[div1]) {
				break;
			}
			if ((*p1)[div1 - 1] > (*p2)[div2]) {
				end1 = div1;
			}
			else {
				start1 = div1;
			}
			div1 = (start1 + end1) >> 1;
			div2 = halfSize - div1;
		}
		if (div2 != 0 && (*p2)[div2 - 1] > (*p1)[div1]) {
			div1++;
			div2--;
		}
		if (div1 == 0) {
			max_left = (*p2)[div2 - 1];
			if (div2 == p2->size()) {
				min_right = (*p1)[div1];
			}
			else {
				min_right = (*p1)[div1] < (*p2)[div2] ? (*p1)[div1] : (*p2)[div2];
			}
		}
		else if (div1 == p1->size()) {
			min_right = (*p2)[div2];
			if (div2 == 0) {                         // consider [1,2] [3,4]
				max_left = (*p1)[div1 - 1];
			}
			else {
				max_left = (*p1)[div1 - 1] > (*p2)[div2 - 1] ? (*p1)[div1 - 1] : (*p2)[div2 - 1];
			}
		}
		else {
			min_right = (*p1)[div1] < (*p2)[div2] ? (*p1)[div1] : (*p2)[div2];
			max_left = (*p1)[div1 - 1] > (*p2)[div2 - 1] ? (*p1)[div1 - 1] : (*p2)[div2 - 1];
		}
		if (isAver) {
			return (max_left + min_right) / 2.0;
		}
		else {
			return min_right;
		}
	}
};
*/

//improved version: the only difference is in line 29-37 and line 101-109 (simply changed if-else judgement sequence)
class Solution1 {
public:
	static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> *p1, *p2;
		int totSize = nums1.size() + nums2.size();
		int halfSize = totSize >> 1;
		bool isAver = (totSize == (halfSize << 1));
		if (nums1.size() <= nums2.size()) {
			p1 = &nums1;
			p2 = &nums2;
		}
		else {
			p1 = &nums2;
			p2 = &nums1;
		}
		if (p1->size() == 0) {
			return isAver ? ((*p2)[halfSize - 1] + (*p2)[halfSize]) / 2.0 : (*p2)[halfSize];
		}
		int size1 = p1->size(), start1 = 0, end1 = size1,
			div1 = (start1 + end1) >> 1, div2 = halfSize - div1; // div is a division mark which is not included in the left part

		int max_left, min_right;
		while (div1 != start1) {               // consider limitations. The judgment is important. Consider why it is like this.
			if ((*p1)[div1 - 1] > (*p2)[div2]) {  // consider why there is no need to judge whether div1 >= 1
				end1 = div1;
			}
			else if ((*p2)[div2 - 1] > (*p1)[div1]) { // consider why there is no need to judge whether div2 >= 1
				start1 = div1;
			}
			else {
				break;
			}
			div1 = (start1 + end1) >> 1;
			div2 = halfSize - div1;
		}
		if (div2 != 0 && (*p2)[div2 - 1] > (*p1)[div1]) {
			div1++;
			div2--;
		}
		if (div1 == 0) {
			max_left = (*p2)[div2 - 1];
			if (div2 == p2->size()) {
				min_right = (*p1)[div1];
			}
			else {
				min_right = (*p1)[div1] < (*p2)[div2] ? (*p1)[div1] : (*p2)[div2];
			}
		}
		else if (div1 == p1->size()) {
			min_right = (*p2)[div2];
			if (div2 == 0) {                         // consider [1,2] [3,4]
				max_left = (*p1)[div1 - 1];
			}
			else {
				max_left = (*p1)[div1 - 1] > (*p2)[div2 - 1] ? (*p1)[div1 - 1] : (*p2)[div2 - 1];
			}
		}
		else {
			min_right = (*p1)[div1] < (*p2)[div2] ? (*p1)[div1] : (*p2)[div2];
			max_left = (*p1)[div1 - 1] > (*p2)[div2 - 1] ? (*p1)[div1 - 1] : (*p2)[div2 - 1];
		}
		if (isAver) {
			return (max_left + min_right) / 2.0;
		}
		else {
			return min_right;
		}
	}
};

