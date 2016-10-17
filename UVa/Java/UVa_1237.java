import java.util.ArrayList;
import java.util.Scanner;

class UVa_1237 {
	
	public static void main(String args[]) {
		new UVa_1237();
	}
	
	int t;
	
	public UVa_1237() {
		
		Scanner input = new Scanner(System.in);
		
		t = input.nextInt();
		
		for(int i = 0;i<t;i++) {
			
			int dataBaseSize = input.nextInt();
			ArrayList<Company> makers = new ArrayList();
			for(int j = 0;j<dataBaseSize;j++) {
				String name = input.next();
				int low = input.nextInt();
				int high = input.nextInt();
				makers.add(new Company(name, low, high));
				
			}
			
			int queryCount = input.nextInt();
			int[] queries = new int[queryCount];
			for(int j = 0;j<queryCount;j++){
				queries[j] = input.nextInt();
			}
			for(int j = 0;j<queryCount;j++) {
				int query = queries[j];
				String result = null;
				for(int k = 0;k<dataBaseSize;k++) {
					Company maker = makers.get(k);
					if(maker.low <= query && maker.high >= query) {
						if(result == null) {
							result = maker.name;
						} else {
							result = null;
							break;
						}
					}
				}
				if(result == null) {
					System.out.println("UNDETERMINED");
				} else {
					System.out.println(result);
				}
			}
			
			if(i != t - 1)
				System.out.println();
			
		}
		
	}
	
}


class Company {
	public int low,high;
	public String name;
	public Company(String name, int low, int high) {
		this.name = name;
		this.low = low;
		this.high = high;
	}
	
}