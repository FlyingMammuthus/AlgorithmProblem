import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map.Entry;


/* Description:
 * Provided a 4x4 (16) grid, 15 of 16 units have their number (1-15) 
 * and the other unit is blank. For each step, blank uint can be exchanged
 * with its adjacent unit.
 * Find a solution to exchange units so that they are in correct order.
 */	
class track {
	public boolean isExpand;
	private LinkedList<Character> direction;

	track() {
		isExpand = false;
		direction = new LinkedList<Character>();
	}

	track(track t) {
		isExpand = t.isExpand;
		direction = new LinkedList<Character>(t.direction);
	}

	void showTrack() {
		System.out.println("Direction for each step:\n");
		for (char dire : direction) {
			System.out.print(dire);
			System.out.print(" ");
		}
		System.out.println();
	}

	void expandTrack(char direct_exp) {
		direction.addLast(direct_exp);
	}
}

public class MoveGird {
	static final int gridSize = 4;
	static final int unitNum = 16; // 16*4->64 bit->long
	static final int blank = 0;	
	
	static track expandGridList(String g_init, String g_stand) {
		if (g_init.equals(g_stand)) {
			return new track();   // no step is needed
		}
		HashMap<String, track> trackMap = new HashMap<String, track>();
		track t_init = new track();
		trackMap.put(g_init, t_init);
		boolean isValid = true; 
		int y_shift[] = {0, 0, -1, 1}, x_shift[] = {-1, 1, 0, 0}; // U D L R
		char d_shift[] = {'U', 'D', 'L', 'R'};
		while (isValid) {
			isValid = false;
			Iterator<Entry<String, track>> iter = trackMap.entrySet().iterator();
			while (iter.hasNext()) {
				Entry<String, track> entry = iter.next();
				String g_pre = entry.getKey();
				track t_pre = entry.getValue();
				int pos_tot = g_pre.indexOf('0');
				int x_pos = pos_tot / gridSize, y_pos = pos_tot % gridSize;
				
				if (t_pre.isExpand) {
					continue;
				}
				
				for (int t_shift = 0; t_shift < 4; ++t_shift) {
					int x_pre = x_pos + x_shift[t_shift], y_pre = y_pos + y_shift[t_shift];
					if (x_pre >= 0 && x_pre < gridSize && y_pre >= 0 && y_pre < gridSize) {
						char c_ins[] = g_pre.toCharArray();
						c_ins[pos_tot] = c_ins[x_pre*gridSize+y_pre];
						c_ins[x_pre*gridSize+y_pre] = '0';
						String g_ins = new String(c_ins);
						track t_ins = new track(t_pre);
						t_ins.expandTrack(d_shift[t_shift]);
						if (g_ins.equals(g_stand)) {
							return t_ins;
						}
						if (!trackMap.containsKey(g_ins)) {
							trackMap.put(g_ins, t_ins);
							isValid = true;
						}
					}					
				}
				
				t_pre.isExpand = true;
				trackMap.put(g_pre, t_pre);
				
				if (isValid) {
					break;
				}
			}
		}	
		return null;
	}
	
	public static void main(String[] args) {
		String g_init = new String("1283570496ACDEBF"),
				g_stand = new String("123456789ABCDEF0");
		track sol = expandGridList(g_init, g_stand);
		sol.showTrack();
	}
}
