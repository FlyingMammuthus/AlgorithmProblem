#include <vector>
#include <string>

using namespace std;
class Solution12 {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<bool> colRec(n, false), lDiag(2 * n - 1, false), rDiag(2 * n - 1, false); // use several recorder to mark the state
		vector<int> qLoc(n, -1);  // use a vector is better than stack
		int rowNum = 0;
		vector<vector<string>> ret;
		while (1) {
			bool isFound = false;
			int ldNum, rdNum, colNum;
			for (colNum = qLoc[rowNum] + 1; colNum < n; ++colNum) {
				ldNum = rowNum + colNum;
				rdNum = colNum - rowNum + n - 1;
				if (!colRec[colNum] && !lDiag[ldNum] && !rDiag[rdNum]) {
					qLoc[rowNum] = colNum;
					isFound = true;
					break;
				}
			}
			if (!isFound) {
				qLoc[rowNum] = -1;
				--rowNum;
				if (rowNum > -1) {
					colNum = qLoc[rowNum];
					ldNum = rowNum + colNum;
					rdNum = colNum - rowNum + n - 1;
					colRec[colNum] = false;
					lDiag[ldNum] = false;
					rDiag[rdNum] = false;
				}
				else {
					break;
				}
			}
			else if (rowNum == n - 1) {
				ret.push_back(transLoctoString(qLoc));
				qLoc[rowNum] = -1;
				--rowNum;
				if (rowNum > -1) {
					colNum = qLoc[rowNum];
					ldNum = rowNum + colNum;
					rdNum = colNum - rowNum + n - 1;
					colRec[colNum] = false;
					lDiag[ldNum] = false;
					rDiag[rdNum] = false;
				}
				else {
					break;
				}
			}
			else {
				colRec[colNum] = true;
				lDiag[ldNum] = true;
				rDiag[rdNum] = true;
				++rowNum;
			}
		}
		return ret;
	}

	vector<string> transLoctoString(vector<int> qLoc) {
		int n = qLoc.size();
		vector<string> ret(n, string(n, '.'));
		for (int i = 0; i < n; ++i) {
			ret[i][qLoc[i]] = 'Q';
		}
		return ret;
	}
};
