#include <vector>
#include <stack>
using namespace std;

/*
//One easy way is recursion
class Solution7 {
public:
	static void solveSudoku(vector<vector<char>>& board) {
		insertSudoku(board, 0, 0);
	}

	static bool insertSudoku(vector<vector<char>>& board, int row, int col) {
		bool isSearched = false;
		for (; row < 9; ++row) {
			for (col = 0; col < 9; ++col) {
				if (board[row][col] == '.') {
					isSearched = true;
					break;
				}
			}
			if (isSearched) {
				break;
			}
		}
		if (isSearched) {
			int row_start = (row / 3)*3, col_start = (col / 3)*3;
			for (int i = 1; i < 10; ++i) {
				isSearched = false;
				char insertChar = '0' + i;
				for (int j = 0; j < 9; ++j) {
					if (board[j][col] == insertChar || board[row][j] == insertChar
						|| board[row_start + j / 3][col_start + j % 3] == insertChar) {
						isSearched = true;
						break;
					}
				}
				if (!isSearched) {
					board[row][col] = insertChar;
					if (insertSudoku(board, row, col)) {
						return true;
					}
					board[row][col] = '.';
				}
			}
			return false;
		}
		return true;
	}
};
*/

/*
//improved method of using stack
class Solution7 {
public:
	static void solveSudoku(vector<vector<char>>& board) {
		typedef pair<int, int> elementPos;
		typedef pair<elementPos, char> elementRec;
		stack<elementRec> boardRec;
		int row = 0, col = 0;
		while (1){
			bool isSearched = false;
			for (; row < 9; ++row) {
				for (col = 0; col < 9; ++col) {
					if (board[row][col] == '.') {
						isSearched = true;
						break;
					}
				}
				if (isSearched) {
					break;
				}
			}
			if (isSearched) {
				char insertChar = '0' + 1;
				isSearched = findNextChar(board, row, col, insertChar);
				if (!isSearched) {               //Caution: how to use push(), elRec is a temporary variable
					elementRec elPick;
					do {
						if (boardRec.empty()) {
							return;
						}
						elPick = boardRec.top();
						boardRec.pop();
						row = elPick.first.first;
						col = elPick.first.second;				
						insertChar = elPick.second + 1;
						board[row][col] = '.';
					} while (!findNextChar(board, row, col, insertChar));

				}
				board[row][col] = insertChar;
				elementPos elPos(row, col);
				elementRec elRec(elPos, insertChar);
				boardRec.push(elRec);
			}
			else {
				return;
			}
		}
	}

	static bool findNextChar(vector<vector<char>>& board, int row, int col, char &cPre) {
		int row_start = (row / 3) * 3, col_start = (col / 3) * 3;
		bool isSearched;
		for (; cPre <= '9'; ++cPre) {
			isSearched = false;
			for (int j = 0; j < 9; ++j) {
				if (board[j][col] == cPre || board[row][j] == cPre
					|| board[row_start + j / 3][col_start + j % 3] == cPre) {
					isSearched = true;
					break;
				}
			}
			if (!isSearched) {
				return true;
			}
		}
		return false;
	}
};
*/

// more improvemnets can be made through using rowRec[9][9], colRec[9][9], boxRec[9][9] to record wether row/col/box has the number
class Solution7 {
public:
	bool rowRec[9][9] = {}, colRec[9][9] = {}, boxRec[9][9] = {};  // rowRec[8][8] means 9th row has '9' or not.
	void initializeRec(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				rowRec[i][j] = colRec[i][j] = boxRec[i][j] = false;  //continous assign
			}
		}
		for (int row = 0; row < 9; ++row) {
			for (int col = 0; col < 9; ++col) {		
				if (board[row][col] != '.') {
					int num = board[row][col] - '0' - 1,
						boxNum = row / 3 * 3 + col / 3;
					rowRec[row][num] = colRec[col][num] = boxRec[boxNum][num] = true;
				}
			}
		}
	}

	void solveSudoku(vector<vector<char>>& board) {
		typedef pair<int, int> elementPos;
		typedef pair<elementPos, char> elementRec;
		stack<elementRec> boardRec;
		int row = 0, col = 0;
		initializeRec(board);
		while (1) {
			bool isSearched = false;
			for (; row < 9; ++row) {
				for (col = 0; col < 9; ++col) {
					if (board[row][col] == '.') {
						isSearched = true;
						break;
					}
				}
				if (isSearched) {
					break;
				}
			}
			if (isSearched) {
				char insertChar = '0' + 1;
				isSearched = findNextChar(board, row, col, insertChar);
				int num, boxNum;
				if (!isSearched) {               //Caution: how to use push(), elRec is a temporary variable
					elementRec elPick;
					do {
						if (boardRec.empty()) {
							return;
						}
						elPick = boardRec.top();
						boardRec.pop();
						row = elPick.first.first;
						col = elPick.first.second;
						insertChar = elPick.second;
						num = insertChar - '0' - 1;
						boxNum = row / 3 * 3 + col / 3;
						board[row][col] = '.';
						rowRec[row][num] = colRec[col][num] = boxRec[boxNum][num] = false;			
						++insertChar;
					} while (!findNextChar(board, row, col, insertChar));
				}
				num = insertChar - '0' - 1;
				boxNum = row / 3 * 3 + col / 3;
				board[row][col] = insertChar;
				elementPos elPos(row, col);
				elementRec elRec(elPos, insertChar);
				boardRec.push(elRec);
				rowRec[row][num] = colRec[col][num] = boxRec[boxNum][num] = true;
			}
			else {
				return;
			}
		}
	}

	bool findNextChar(vector<vector<char>>& board, int row, int col, char &cPre) {
		int boxNum = row / 3 * 3 + col / 3;
		for (int num = cPre - '0' - 1; num < 9; ++num) {
			if (!rowRec[row][num] && !colRec[col][num] && !boxRec[boxNum][num]) {
				cPre = num + 1 + '0';
				return true;
			}
		}
		return false;
	}
};
