#pragma once
#include <vector>

using namespace std;
class Solution11 {
public:
	int jump(vector<int>& nums) {
		int nLen = nums.size(), nStart = 0, nEnd = 0, counter = 0, pStart = nStart, pEnd = nEnd;
		while (nEnd < nLen - 1) {
			pStart = nStart + 1;
			for (int i = nStart; i <= nEnd; ++i) {
				if (nums[i] + i > pEnd) {
					pEnd = nums[i] + i;
				}
			}
			if (pEnd > nEnd) {
				nStart = pStart;
				nEnd = pEnd;
			}
			else {
				return 0;
			}
			++counter;
		}
		return counter;
	}
};
