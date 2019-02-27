#pragma once
#include <vector>

using namespace std;
class Solution9 {
public:
	static int trap(vector<int>& height) {
		int stepNum = height.size();
		int ret = 0;
		if (stepNum > 0) {
			typedef pair<int, int> stepMax;
			typedef vector<stepMax> stepRecorder;
			stepRecorder stpRd(stepNum);
			stpRd[0].first = height[0];
			stpRd[0].second = height[0];
			stpRd[stepNum - 1].first = height[stepNum - 1];
			stpRd[stepNum - 1].second = height[stepNum - 1];
			for (int i = 1; i < stepNum - 1; ++i) {
				stpRd[i].first = height[i] > stpRd[i - 1].first ? height[i] : stpRd[i - 1].first;
			}
			for (int i = stepNum - 2; i > 0; --i) {    //consider 
				stpRd[i].second = height[i] > stpRd[i + 1].second ? height[i] : stpRd[i + 1].second;
			}
			for (int i = 1; i < stepNum - 1; ++i) {
				ret += (stpRd[i].first > stpRd[i].second ? stpRd[i].second : stpRd[i].first) - height[i];
			}
		}
		return ret;
	}
};

//use array instead of pair
/*
class Solution {
public: 
int trap(vector<int>& height) {
if (height.size() < 3)
return 0;
int rightMax[height.size()-1] = {0};
rightMax[height.size()-2] = height[height.size()-1];
for(int i = height.size()-3; i >= 0; i--){
rightMax[i] = max(rightMax[i+1], height[i+1]);
}
int water = 0, curr = 0;
for(int i = 0; i < height.size()-1; i++){
if (height[i] >= curr)
curr = min(height[i], rightMax[i]);
if (curr-height[i] > 0)
water += curr-height[i];
}
return water;
}
};

*/
