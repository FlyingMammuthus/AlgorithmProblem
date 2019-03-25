#pragma once

/* simple method
class Solution24 {
public:
	int maxProfit(vector<int>& prices) {
		int ret = 0, profit = 0, dayNum = prices.size();
		for (int i = 0; i < dayNum - 1; ++i) {
			profit = getMaxForOneTrans(prices, 0, i) + getMaxForOneTrans(prices, i, dayNum - 1);
			if (ret < profit) {
				ret = profit;
			}
		}
		return ret;
	}

	int getMaxForOneTrans(vector<int> &prices, int l, int r) {
		int ret = 0, min = prices[l], profit = 0;
		for (int i = l + 1; i <= r; ++i) {
			profit = prices[i] - min;
			if (profit > ret) {
				ret = profit;
			}
			if (prices[i] < min) {
				min = prices[i];
			}
		}
		return ret;
	}
};
*/

/* Based on the idea, another method can be found */
class Solution24 {
public:
	int maxProfit(vector<int>& prices) {
		int dayNum = prices.size();
		if (dayNum == 0) {
			return 0;
		}
		vector<int> lRec(dayNum), rRec(dayNum);
		int min = prices[0];
		lRec[0] = 0;
		for (int i = 1; i < dayNum; ++i) {
			lRec[i] = prices[i] - min > lRec[i - 1] ? prices[i] - min : lRec[i - 1];
			if (prices[i] < min) {
				min = prices[i];
			}
		}
		int max = prices[dayNum - 1];
		lRec[dayNum - 1] = 0;
		for (int i = dayNum - 2; i >= 0; --i) {
			rRec[i] = max - prices[i] > rRec[i + 1] ? max - prices[i] : rRec[i + 1];
			if (prices[i] > max) {
				max = prices[i];
			}
		}
		int ret = 0, profit;
		for (int i = 0; i < dayNum; ++i) {
			profit = lRec[i] + rRec[i];
			if (profit > ret) {
				ret = profit;
			}
		}
		return ret;
	}
};
