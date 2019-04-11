class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int nSize = nums.size();
        if (nSize == 0) {
            return 0;
        }
        unordered_map<int, bool> isExist;
        for (int i = 0; i < nSize; ++i) {
            if (isExist.find(nums[i]) == isExist.end()) {
                isExist.insert(pair<int, bool>(nums[i], true));
            }
        }
        int maxLen = 0;
        for (int i = 0; i < nSize; ++i) {
            int numPre = nums[i];
            if (isExist[numPre]) {
                isExist[numPre] = false;
                int lenRec = 1;
                numPre = nums[i];
                while (isExist.find(--numPre) != isExist.end()) {
                    isExist[numPre] = false;
                    ++lenRec;
                }
                numPre = nums[i];
                while (isExist.find(++numPre) != isExist.end()) {
                    isExist[numPre] = false;
                    ++lenRec;
                }
                if (lenRec > maxLen){
                    maxLen = lenRec;
                }
            }
        }
        return maxLen;
    }
};
