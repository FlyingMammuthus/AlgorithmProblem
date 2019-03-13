#pragma once
#include <vector>
// basic idea: search each position as it is the top left corner

// improved method : based on Largest Rectabgle In Histogram, search each row to get the maximal.
class Solution19 {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int row = 0, col = 0;
		if ((row = matrix.size()) == 0 || (col = matrix[0].size()) == 0)
			return 0;
		vector<int> h_row(col, 0);
		int ret = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				h_row[j] = matrix[i][j] != '0' ? h_row[j] + 1 : 0;
			}
			vector<int> leftRec(col), rightRec(col);
			leftRec[0] = -1;
			for (int p = 0; p < col; ++p) {
				int q = p - 1;
				while (q >= 0 && h_row[q] >= h_row[p]) {
					q = leftRec[q];
				}
				leftRec[p] = q;
			}
			rightRec[col - 1] = col;
			for (int p = col - 1; p >= 0; --p) {
				int q = p + 1;
				while (q < col && h_row[q] >= h_row[p]) {
					q = rightRec[q];
				}
				rightRec[p] = q;
			}
			for (int p = 0; p < col; ++p) {
				ret = max(ret, (rightRec[p] - leftRec[p] - 1)*h_row[p]);
			}
		}
		return ret;
	}
};
