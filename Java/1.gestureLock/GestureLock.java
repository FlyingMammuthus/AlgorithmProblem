import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

/* Desciption :
 * Given n*n square point array with some points unreachable, 
 * return the number of patterns which can be drawn.
 * Principles for pattern :
 * 1. Like gesture lock, the pattern can be drawn by a continuous route 
 *    with every point on the route reached only once.
 * 2. Skipping one or several middle points is permitted
 *    but the pattern might be the same. For example:    
 *             
 *      for .  .  . ,                 .   .<- .     is permitted 
 *                                    |       ^
 *                                    |_______|
 *      but it has the same pattern as   .->.->.    
 *      
 * input :
 * 1
 * ooo
 * xox
 * xxx
 *      
 * the answer should be 22 (see Fig onePsiibleSolution)
 */


class gesturePattern{
	static int[] xLineIndex;
	static int[] yLineIndex;
	static int[][] pointIndex;
	static int length;
	static int pointNum;
	boolean[][] pattern;  
	boolean[] isPointSel;
	int lastPoint;
	
	gesturePattern(){
		pointNum = 0;
		pattern = null;
		isPointSel = null;
		lastPoint = -1;
	}
	
	gesturePattern(int lastP){
		pattern = new boolean[pointNum][pointNum];
		isPointSel = new boolean[pointNum];
		isPointSel[lastP] = true;
		lastPoint = lastP;
	}
	
	gesturePattern(gesturePattern src){
		copyPattern(src);
	}
	
	void copyPattern(gesturePattern src){
		pattern = new boolean[pointNum][pointNum];
		isPointSel = new boolean[pointNum];
		lastPoint = src.lastPoint;
		for (int i = 0; i < pointNum; ++i) {
			for (int j = 0; j < pointNum; ++j) {
				pattern[i][j] = src.pattern[i][j];
			}
		}
		for (int i = 0; i < pointNum; ++i) {
			isPointSel[i] = src.isPointSel[i];
		}
	}
	
	boolean insertEdge(int insPoint) {
		if (isPointSel[insPoint]) {
			return false;
		}
		int x_min = xLineIndex[insPoint], y_min = yLineIndex[insPoint], x_max = xLineIndex[lastPoint], y_max = yLineIndex[lastPoint];
		if (x_min == x_max) {
			int x = x_min;
			if (y_min > y_max) {
				int trans = y_min;
				y_min = y_max;
				y_max = trans;
			}
			int y_low = y_min, y_high = y_max;
			for (int yFront = y_min; yFront <= y_max; ++yFront) {
				int pointFront = pointIndex[x][yFront];
				if (pointFront >= 0) {
					for (int yBack = 0; yBack < length; ++yBack) {
						int pointBack = pointIndex[x][yBack];
						if ((pointBack >= 0) && pattern[pointFront][pointBack]) {
							pattern[pointFront][pointBack] = false;
							pattern[pointBack][pointFront] = false;
							if (y_low > yFront) {
								y_low = yFront;
							}
							if (y_low > yBack) {
								y_low = yBack;
							}
							if (y_high < yFront) {
								y_high = yFront;
							}
							if (y_high < yBack) {
								y_high = yBack;
							}
						}
					}
				}
			}
			pattern[pointIndex[x][y_low]][pointIndex[x][y_high]] = true;
			pattern[pointIndex[x][y_high]][pointIndex[x][y_low]] = true;
			isPointSel[insPoint] = true;
			lastPoint = insPoint;
		}
		else {
			if (x_min > x_max) {
				int trans = x_min;
				x_min = x_max;
				x_max = trans;
				trans = y_min;
				y_min = y_max;
				y_max = trans;
			}
			int x_low = x_min, y_low = y_min, x_high = x_max, y_high = y_max;
			float slope = ((float)(y_max - y_min)) / (x_max - x_min);
			for (int xFront = x_min; xFront <= x_max; ++xFront) {
				int yFront = (int) (y_min + (xFront - x_min) * slope + 0.5);
				if ((yFront - y_min)*(x_max - x_min) == (y_max - y_min)*(xFront - x_min) && yFront < length) {
					int pointFront = pointIndex[xFront][yFront];
					if (pointFront >= 0) {
						for (int xBack = 0; xBack < length; ++xBack) {
							int yBack = (int) (y_min + (xBack - x_min) * slope + 0.5);
							if ((yBack - y_min) * (x_max - x_min) == (y_max - y_min) * (xBack - x_min) && yBack < length) {
								int pointBack = pointIndex[xBack][yBack];
								if ((pointBack >= 0) && (pattern[pointFront][pointBack])) {
									pattern[pointFront][pointBack] = false;
									pattern[pointBack][pointFront] = false;
									if (x_low > xFront) {
										x_low = xFront;
										y_low = yFront;
									}
									if (x_low > xBack) {
										x_low = xBack;
										y_low = yBack;
									}
									if (x_high < xFront) {
										x_high = xFront;
										y_high = yFront;
									}
									if (x_high < xBack) {
										x_high = xBack;
										y_high = yBack;
									}
								}
							}
						}
					}
				}
			}
			pattern[pointIndex[x_low][y_low]][pointIndex[x_high][y_high]] = true;
			pattern[pointIndex[x_high][y_high]][pointIndex[x_low][y_low]] = true;
			isPointSel[insPoint] = true;
			lastPoint = insPoint;
		}
		return true;
	}
	
	boolean isSamePattern(boolean[][] comp) {
		for (int i = 0; i < pointNum; ++i) {
			for (int j = i; j < pointNum; ++j) {
				if (pattern[i][j] != comp[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	
	boolean isSameRoute(gesturePattern comp) {
		return ((lastPoint == comp.lastPoint) && isSamePattern(comp.pattern));
	}
	
	static void drawGesturePattern(boolean[][] GesPattern) {
		int interval = (length - 1) << 1;
		int drawnPatSize = (length - 1)*interval + 1;
		char [][] drawnPat = new char[drawnPatSize][drawnPatSize];
		for (int i = 0; i < drawnPatSize; ++i) {
			Arrays.fill(drawnPat[i], ' ');
		}
		for (int i = 0; i < pointNum; ++i) {
			for (int j = i +1; j < pointNum; ++j) {
				if (GesPattern[i][j]) {
					int xFront = xLineIndex[i]*interval, yFront = yLineIndex[i]*interval,
						xBack = xLineIndex[j]*interval, yBack = yLineIndex[j]*interval;
					if (xFront == xBack) {
						int x = xFront;
						for (int y = yFront; y <= yBack; ++y) {
							drawnPat[x][y] = '.';
						}
					}
					else
					{
						if (xFront > xBack) {
							int trans = xFront;
							xFront = xBack;
							xBack = trans;
							trans = yFront;
							yFront = yBack;
							yBack = trans;
						}
						float slope = ((float)(yBack - yFront)) / (xBack - xFront);
						for (int x = xFront; x <= xBack; ++x) {
							int y = (int) (yFront + (x - xFront) * slope + 0.5);
							if ((y - yFront)*(x - xBack) == (y - yBack)*(x - xFront)) {
								drawnPat[x][y] = '.';
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				if (pointIndex[i][j] >= 0) {
					drawnPat[i*interval][j*interval] = 'o';
				}
				else {
					drawnPat[i*interval][j*interval] = 'x';
				}
			}
		}
		for (int i = 0; i < drawnPatSize; ++i) {
			for (int j = 0; j < drawnPatSize; ++j) {
				System.out.print(drawnPat[i][j]);
			}
			System.out.println();
		}
	}
}

public class GestureLock {

	static LinkedList<boolean [][]> pattern_rec; 
	public static int MaxNumOfPattern(int length, char[][] grid) {
		int pointIndex[][] = new int[length][length];
		int pointNum = CountValidNum(length, grid, pointIndex);
		if (pointNum < 1) {
			return 0;
		}
		int xLineIndex[] = new int[pointNum], yLineIndex[] = new int[pointNum];
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				if (pointIndex[i][j] > -1) {
					xLineIndex[pointIndex[i][j]] = i;
					yLineIndex[pointIndex[i][j]] = j;
				}
			}
		}
		gesturePattern.length = length;
		gesturePattern.pointIndex = pointIndex;
		gesturePattern.xLineIndex = xLineIndex;
		gesturePattern.yLineIndex = yLineIndex;
		gesturePattern.pointNum = pointNum;
		int maxNum = 0;
		LinkedList<gesturePattern> pattern_prev = null, pattern_cu = new LinkedList<gesturePattern>();
		pattern_rec = new LinkedList<boolean [][]>();
		for (int i = 0; i < pointNum; ++i) {
			pattern_cu.add(new gesturePattern(i));
		}
		while (!(maxNum != 0 && pattern_cu.isEmpty())) {
			pattern_prev = pattern_cu;
			pattern_cu = new LinkedList<gesturePattern>();
			Iterator<gesturePattern> it = pattern_prev.iterator();
			while (it.hasNext()) {
				gesturePattern pattern_pick = it.next(), pattern_ins;
				for (int i = 0; i < pointNum; ++i) {
					pattern_ins = new gesturePattern(pattern_pick);
					if (pattern_ins.insertEdge(i)) {
						boolean routeExis = false;
						Iterator<gesturePattern> it_cu = pattern_cu.iterator();
						while (it_cu.hasNext()) {
							routeExis = pattern_ins.isSameRoute(it_cu.next());
							if (routeExis) {
								break;
							}
						}
						if (!routeExis) {
							pattern_cu.add(pattern_ins);
							boolean patternExis = false;
							Iterator<boolean [][]> it_pattern = pattern_rec.iterator();
							while (it_pattern.hasNext()) {
								patternExis = pattern_ins.isSamePattern(it_pattern.next());
								if (patternExis) {
									break;
								}
							}
							if (!patternExis) {
								++maxNum;
								pattern_rec.add(pattern_ins.pattern);
							}
						}
					}
				}
			}
		}				
		return maxNum;
	}

	private static int CountValidNum(int length, char[][] grid, int[][] index) {
		int pointNum = 0;
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				if (grid[i][j] == 'o') {
					index[i][j] = pointNum++;
				}
				else if (grid[i][j] == 'x') {
					index[i][j] = -1;
				}
				else {
					return -1;
				}
			}
		}	
		return pointNum;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int caseNum = scan.nextInt();
		int length = 3;
		char [][][]grid = new char[caseNum][][];
		// o means it can be selected; x means the point cannot 
		for (int i = 0; i < caseNum; ++i) {
			grid[i] = new char[length][length];
			for (int j = 0; j < length; ++j) {
				char[] s = scan.next().toCharArray();
				for (int k = 0; k < length; ++k) {
					grid[i][j][k] = s[k];
				}
			}
		}
		scan.close();
		for (int i = 0; i < caseNum; ++i) {
			System.out.println("————————————————————————————————————————————————————");
			System.out.println("Case " + i + " :");
			int maxNum = MaxNumOfPattern(length, grid[i]);
			System.out.println(maxNum);
			Iterator<boolean [][]> it_pat = pattern_rec.iterator();
			int counter = 0;
			while(it_pat.hasNext()) {
				System.out.println("****************************************");
				System.out.println(++counter);
				gesturePattern.drawGesturePattern(it_pat.next());
			}
		}
		
	}

}
