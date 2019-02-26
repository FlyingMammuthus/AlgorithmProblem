#include <vector>

using namespace std;

class Solution8 {
public:
	int firstMissingPositive(vector<int>& nums) {
		int vlen = nums.size();
		vector<bool> rec(vlen, false);
		int i;
		for (i = 0; i < vlen; ++i) {
			if (nums[i] > 0 && nums[i] <= vlen) {
				rec[nums[i] - 1] = true;
			}
		}
		for (i = 0; i < vlen; ++i) {
			if (rec[i] == false) {
				break;
			}
		}
		return i + 1;
	}
};
