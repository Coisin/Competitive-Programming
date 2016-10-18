import java.util.ArrayList;
import java.util.Scanner;

class UVa_10567 {
	
	public static void main(String args[]) {
		new UVa_10567();
	}
	
	int caseNumber = 0;
	
	ArrayList<Integer>[] states = new ArrayList[123];
	String cases[];
	String sequence;
	public UVa_10567() {
		
		for(int i = 0;i<states.length;i++) {
			states[i] = new ArrayList();
		}
		
		Scanner input = new Scanner(System.in);
		
		sequence = input.next();
		for(int i = 0;i<sequence.length();i++) {
			char c = sequence.charAt(i);
			states[(int)c].add(i);
		}
		int cases = input.nextInt();
		this.cases = new String[cases];
		
		for(int i = 0;i<cases;i++) {
			this.cases[i] = input.next();
		}
		
		for(;caseNumber < cases;caseNumber++) {
			if(process(0, -1)) {
				System.out.println("Matched " + low + " " + high);
			} else {
				System.out.println("Not matched");
			}
 		}
		
	}
	
	int NOPE = 1000000000;
	int answer = -1;
	int low, high;
	
	public boolean process(int index, int subject) {
		
		if(index == cases[caseNumber].length()) {
			high = subject;
			return true;		
		}
		
		char c = cases[caseNumber].charAt(index);
		ArrayList<Integer> state = states[(int)c];
		int newSubject;
		if((newSubject = binarySearch(state, 0, state.size() - 1, subject)) != NOPE) {
			if(index == 0) {
				low = newSubject;
			}
			return process(index + 1, newSubject);
		}
		return false;
		
	}
	
	public int binarySearch(ArrayList<Integer> state, int left, int right, int subject) {
		
		if(right < left) {
			return NOPE;
		}
		
		int middle = (left + right) / 2;
		if(state.get(middle) > subject) {
			int newVal;
			return ((newVal = binarySearch(state, left, middle - 1, subject)) < state.get(middle))?newVal:state.get(middle);
		} else {
			return binarySearch(state, middle + 1, right, subject);
		}
		
	}
	
}
