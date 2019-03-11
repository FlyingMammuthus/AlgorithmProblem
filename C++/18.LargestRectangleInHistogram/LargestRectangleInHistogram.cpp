#pragma once
#include <vector>

using std::vector;

/* basic idea: check each area height
class Solution18 {
public:
	int largestRectangleArea(vector<int>& heights) {
		int ret = 0;
		for (int i = 0; i < heights.size(); ++i) {
			int h = heights[i];
			int w = 1, j = i;
			while (--j >= 0 && heights[j] >= h) {
				++w;
			}
			j = i;
			while (++j < heights.size() && heights[j] >= h) {
				++w;
			}
			w *= h;
			if (ret < w) {
				ret = w;
			}
		}
		return ret;
	}
};
*/

// another modified way using extra memory to record position
class Solution18 {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 0)
			return 0;
		vector<int> leftRec(heights.size()), rightRec(heights.size());
		leftRec[0] = -1;  // the leftest position which is smaller than the present element
		for (int i = 0; i < heights.size(); ++i) {
			int j = i - 1;
			while (j >= 0 && heights[j] >= heights[i])
				j = leftRec[j];
			leftRec[i] = j;

		}
		rightRec[heights.size()-1] = heights.size(); // the leftest position which is larger than the present element
		for (int i = heights.size()-1; i >= 0; --i) {
			int j = i + 1;
			while (j < heights.size() && heights[j] >= heights[i])
				j = rightRec[j];
			rightRec[i] = j;
		}
		int ret = 0;
		for (int i = 0; i < heights.size(); ++i) {
			ret = max(ret, (rightRec[i] - leftRec[i] - 1)*heights[i]);
		}
		return ret;
	}
};
