import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

/* Description :
 * Given several member with different ability A and B, 
 * select a certain number of members for A and B so that
 * the lowest ability value of all selected members are highest.
 * For members who are selected for their ability A, they cannot be 
 * selected for ability B and only their ability value of A works 
 * when calculating the lowest ability value. 
 * And it is the same case for those who are selected for their ability B. 
 * 
 * input :
 * 1
 * 10
 * 3 4
 * 100 95
 * 87  94
 * 95  95
 * 90  92
 * 89  70
 * 85  96
 * 80  84
 * 0   100
 * 97  0
 * 99  99
 */

class teamMember    
{    
    int num;
    int abilityA;
    int abilityB;
}  

class abilityA implements Comparator<teamMember>    
{ 
	public int compare(teamMember B, teamMember A) {
		if (A.abilityA != B.abilityA) {
			return A.abilityA - B.abilityA;
		} else {
			return A.abilityB - B.abilityB;
		}
	}
}     

class abilityB implements Comparator<teamMember>    
{ 
	public int compare(teamMember B, teamMember A) {
		if (A.abilityB != B.abilityB) {
			return A.abilityB - B.abilityB;
		} else {
			return A.abilityA - B.abilityA;
		}
	}
}     

public class StrongestTeam {
	
	public static int maxAbility(int numA, int numB, int memNum, int[] abilityA, int[] abilityB) {
		int rankA[] = new int[memNum], rankB[] = new int[memNum];
		sortAbility(memNum, abilityA, abilityB, rankA, rankB);
		LinkedList<Integer> selectA = new LinkedList<Integer>(), selectB = new LinkedList<Integer>();
		initilizeSelction(numA, numB, memNum, abilityA, abilityB, rankA, rankB, selectA, selectB);
		int minAbi[] = new int[1], minAbi_cu = 0;
		minAbi[0] = abilityA[selectA.getLast()];
		if (abilityB[selectB.getLast()] < minAbi[0]) {
			minAbi[0] = abilityB[selectB.getLast()];
		}
		while(minAbi_cu != minAbi[0]) {
			minAbi_cu = minAbi[0];
			if (minAbi_cu == abilityA[selectA.getLast()]) {
				updateMinAbility(abilityA, abilityB, selectA, selectB, minAbi);
			}
			else {
				updateMinAbility(abilityB, abilityA, selectB, selectA, minAbi);
			}
		}
		return minAbi[0];
	}


	public static void sortAbility(int memNum, int[] abilityA, int[] abilityB, int[] rankA, int[] rankB) {
		teamMember member[] = new teamMember[memNum];
		for (int i = 0; i < memNum; ++i) {
			member[i] = new teamMember();
			member[i].num = i;
			member[i].abilityA = abilityA[i];
			member[i].abilityB = abilityB[i];
		}
		Arrays.sort(member, 0, memNum, new abilityA());
		for (int i = 0; i < memNum; ++i) {
			rankA[i] = member[i].num;
		}
		Arrays.sort(member, 0, memNum, new abilityB());
		for (int i = 0; i < memNum; ++i) {
			rankB[i] = member[i].num;
		}
	}
	
	
	private static void initilizeSelction(int numA, int numB, int memNum, int[] abilityA, int[] abilityB,
			int[] rankA, int[] rankB, LinkedList<Integer> selectA, LinkedList<Integer> selectB) {
		int pA = 0, pB = 0;
		while (selectA.size() < numA && selectB.size() < numB) {
			if ((abilityA[rankA[pA]] < abilityB[rankB[pB]]) || 
					((abilityA[rankA[pA]] == abilityB[rankB[pB]]) && (abilityB[rankA[pA]] <= abilityA[rankB[pB]]))){
				if (!selectA.contains(rankB[pB])) {
					selectB.add(rankB[pB]);
				}
				++pB;
			}
			else {
				if (!selectB.contains(rankA[pA])) {
					selectA.add(rankA[pA]);
				}
				++pA;
			}
		}
		while (selectA.size() < numA) {
			if (!selectB.contains(rankA[pA])) {
				selectA.add(rankA[pA]);
			}
			++pA;
		}
		while (selectB.size() < numB) {
			if (!selectA.contains(rankB[pB])) {
				selectB.add(rankB[pB]);
			}
			++pB;
		}
	}

	private static void updateMinAbility(int[] abilityA, int[] abilityB, LinkedList<Integer> selectA,
			LinkedList<Integer> selectB, int[] minAbi) {
		if (abilityA[selectA.getLast()] < abilityB[selectA.getLast()]) {
			int excIndex = 0, minAbi_cu = abilityA[selectA.getLast()], listIndex = -1;
			for (Iterator<Integer> it = selectB.iterator(); it.hasNext();) {
				excIndex = it.next();
				++listIndex;
				if (abilityA[excIndex] > minAbi_cu) {
					break;
				}
			}
			if (abilityA[excIndex] > minAbi_cu) {
				selectB.remove(listIndex);
				InsertAbi(abilityA, selectA, excIndex);
				excIndex = selectA.removeLast();
				InsertAbi(abilityB, selectB, excIndex);
				minAbi[0] = selectA.getLast();
				if (minAbi[0] > selectB.getLast()) {
					minAbi[0] = selectB.getLast();
				}
			}
		}
	}

	private static void InsertAbi(int[] ability, LinkedList<Integer> select, int excIndex) {
		int insIndex = -1, AbiIndex = 0;
		for (Iterator<Integer> it = select.iterator(); it.hasNext();) {
			AbiIndex = it.next();
			++insIndex;
			if (ability[AbiIndex] < ability[excIndex]) {
				break;
			}
			select.add(insIndex, excIndex);
		}
		
	}


	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int caseNum = scan.nextInt();
		int memNum[] = new int[caseNum], numA[] = new int[caseNum], numB[] = new int[caseNum],
				abilityA[][] = new int[caseNum][], abilityB[][] = new int[caseNum][];
		for (int i = 0; i < caseNum; ++i) {
			memNum[i] = scan.nextInt();
			numA[i] = scan.nextInt();
			numB[i] = scan.nextInt();
			abilityA[i] = new int[memNum[i]];
			abilityB[i] = new int[memNum[i]];
			for (int j = 0; j < memNum[i]; ++j) {
				abilityA[i][j] = scan.nextInt();
				abilityB[i][j] = scan.nextInt();
			}
		}
		scan.close();
		
		for (int i = 0; i < caseNum; ++i) {
			int minAbi = maxAbility(numA[i], numB[i], memNum[i], abilityA[i], abilityB[i]);
			System.out.println(minAbi);
		}
	}

}
