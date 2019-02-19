import java.util.Scanner;

/* Description :
 * Given a central and axial symmetric pattern (tile pattern),
 * use the pattern to fill one wall so that 
 * the pattern on wall is still central and axial symmetric.
 * 
 * input :
 * 1
 * 3 7
 * xox
 * o1o
 * xox
 */


public class TileStitch {

	public static void stitchTile(int tileSize, int wallSize, char[][] tilePattern) {
		int tileNum = wallSize / tileSize;
		int cornerSize = wallSize - tileNum*tileSize;
		if (cornerSize % 2 == 0) {
			cornerSize >>= 1;
		}
		else {
			cornerSize = (cornerSize + tileSize) >> 1;
			--tileNum;
		}
		for (int i = tileSize - cornerSize; i < tileSize; ++i ) {
			outputPatternPart(i, tileSize - cornerSize, cornerSize, tilePattern);
			for (int j = 0; j < tileNum; ++j) {
				outputPatternPart(i, 0, tileSize, tilePattern);
			}
			outputPatternPart(i, 0, cornerSize, tilePattern);
			System.out.println();
		}
		
		for (int k = 0; k < tileNum; ++k) {
			for (int i = 0; i < tileSize; ++i ) {
				outputPatternPart(i, tileSize - cornerSize, cornerSize, tilePattern);
				for (int j = 0; j < tileNum; ++j) {
					outputPatternPart(i, 0, tileSize, tilePattern);
				}
				outputPatternPart(i, 0, cornerSize, tilePattern);
				System.out.println();
			}
		}
		
		
		for (int i = 0; i < cornerSize; ++i ) {
			outputPatternPart(i, tileSize - cornerSize, cornerSize, tilePattern);
			for (int j = 0; j < tileNum; ++j) {
				outputPatternPart(i, 0, tileSize, tilePattern);
			}
			outputPatternPart(i, 0, cornerSize, tilePattern);	
			System.out.println();
		}

	}
	
	public static void outputPatternPart(int rowBegin, int colBegin, int length, char[][] tilePattern) {
		for (int i = 0; i < length; ++i) {
			System.out.print(tilePattern[rowBegin][colBegin + i]);
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int caseNum = scan.nextInt();
		int tileSize[] = new int[caseNum], wallSize[] = new int[caseNum];
		char tilePattern[][][] = new char[caseNum][][];
		for (int i = 0; i < caseNum; ++i) {
			tileSize[i] = scan.nextInt();
			wallSize[i] = scan.nextInt();
			tilePattern[i] = new char[tileSize[i]][tileSize[i]];
			for (int j = 0; j < tileSize[i]; ++j) {	
				char[] s = scan.next().toCharArray(); 
				for (int k = 0; k < tileSize[i]; ++k) {
					tilePattern[i][j][k] = s[k];		
				}
			}

		}
		scan.close();
		for (int i = 0; i < caseNum; ++i) {
			System.out.println();
			stitchTile(tileSize[i], wallSize[i], tilePattern[i]);
		}
	}

}
