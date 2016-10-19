import java.util.Scanner;

class UVa_11953 {
	
	public static void main(String args[]) {
		new UVa_11953();
	}
	
	int testCases;
	int gridSize;
	int[][] grid;
	
	int answer = 0;
	
	int changeX[] = {-1, 0, 1, 0};
	int changeY[] = {0, -1, 0, 1};
	
	public UVa_11953() {
		
		Scanner input = new Scanner(System.in);
		
		testCases = input.nextInt();
		
		for(int caseNumber = 1; caseNumber <= testCases; caseNumber++) {
			
			gridSize = input.nextInt();
			grid = new int[gridSize][gridSize];
			for(int row = 0;row<gridSize;row++) {
				String line = input.next();
				for(int column = 0;column<gridSize;column++) {
					char c = line.charAt(column);
					int val = 0;
					switch(c) {
					case '.':
						val = 0;
						break;
					case 'x':
						val = 1;
						break;
					default:
						val = 2;
						
					}
					grid[row][column] = val;
				}
			}
			
			for(int row = 0;row<gridSize;row++) {
				for(int column = 0;column<gridSize;column++) {
					if(grid[row][column] == 1) {
						answer++;
						paint(1, 0, column, row);
					}
				}
			}
			
			System.out.println("Case "+caseNumber+": " + answer);
			answer = 0;
			
		}
		
	}
	
	public void paint(int c1, int c2, int x, int y) {
		if(x < 0 || y < 0 || x == gridSize || y == gridSize || grid[y][x] == c2)return;
		
		grid[y][x] = c2;
		
		for(int i = 0;i<4;i++) {
			paint(c1, c2, x + changeX[i], y + changeY[i]);
		}
		
	}
	
}
