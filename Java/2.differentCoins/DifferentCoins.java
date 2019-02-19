import java.util.Scanner;

/* Description : 
 * There are two kinds of coins with different face values.
 * One kind of coins is normal ones which can be picked in any number, having n1 face values.
 * The other kind is commemorative coins which can be picked no more than one, having n2 face values.
 * Calculate how many ways of picking coins there are in which an m values can be obtained.
 * The number of ways should be done such operations on : num = num % 1000000007
 * 
 * input pattern : 
 * n1 n2 m
 * v11 v12 ... v1n1
 * v21 v22 ... v2n2
 * output pattern :
 * num
 * 
 * input : 
 * 3 1 5
 * 1 2 3
 * 1
 * 
 * output :
 * 9
 * 
 * input : 10 5 10000 1 2 3 5 7 11 13 17 19 23 2 4 8 16 32
 */
public class DifferentCoins {

	static final int mod_num = 1000000007;
	public static int findNumOfdiffCoinPicking(int[] val_norm, int[] val_comm, int val_tar) {
		int typeNum_norm = val_norm.length, typeNum_comm = val_comm.length;
		int typeNum_tot = typeNum_norm + typeNum_comm;
		int[][] num_rec = new int[typeNum_tot][val_tar+1];
		for (int type = 0; type < typeNum_tot; ++type) {
			num_rec[type][0] = 1;
		}
		for (int val = 0; val <= val_tar; val += val_norm[0]) {
			num_rec[0][val] = 1;
		}
		
		for (int val = 1; val <= val_tar; ++val) {
			for (int type = 1; type < typeNum_norm; ++type) {
				for (int num = 0; num*val_norm[type] <= val; ++num) {
					num_rec[type][val] += num_rec[type-1][val-num*val_norm[type]];
					if (num_rec[type][val] >= mod_num) {
						num_rec[type][val] -= mod_num;
					}
				}
			}
			for (int type = typeNum_norm; type < typeNum_tot; ++type) {
				for (int num = 0; (num < 2) && (num*val_comm[type-typeNum_norm] <= val); ++num) {
					num_rec[type][val] += num_rec[type-1][val-num*val_comm[type-typeNum_norm]];
					if (num_rec[type][val] >= mod_num) {
						num_rec[type][val] -= mod_num;
					}
				}
			}
		}	
		return num_rec[typeNum_tot-1][val_tar];
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int typeNum_norm = scan.nextInt(),
			typeNum_comm = scan.nextInt(),
			val_tar = scan.nextInt();
		int []val_norm = new int[typeNum_norm];
		int []val_comm = new int[typeNum_comm];
		for (int i = 0; i < typeNum_norm; ++i) {
			val_norm[i] = scan.nextInt();
		}
		for (int i = 0 ; i < typeNum_comm; ++i) {
			val_comm[i] = scan.nextInt();
		}
		System.out.println(findNumOfdiffCoinPicking(val_norm, val_comm, val_tar));
	}
}
