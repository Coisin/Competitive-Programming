import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
ID: odwyero2
LANG: JAVA
TASK: transform
*/

public class transform {
	
	public static void main(String args[]) {
		new transform();
	}
	
	public transform() {
		try {
			readIn();
			process();
			output();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	int n;
	char[][] oldPattern, newPattern;
	
	public void readIn() throws IOException{
		Scanner in = new Scanner(new FileReader("transform.in"));
		n = in.nextInt();
		oldPattern = new char[n][n];
		newPattern = new char[n][n];
		for(int i = 0;i<n;i++) {
			String row = in.next();
			for(int j = 0;j<n;j++)oldPattern[i][j] = row.charAt(j);}
		for(int i = 0;i<n;i++) {
			String row = in.next();
			for(int j = 0;j<n;j++)newPattern[i][j] = row.charAt(j);}
	}
	
	int ans = -1;
	
	public void process() {
		
		int a = one(oldPattern, 1);
		if(a != -1) {
			ans = a;
			return;
		}
		a = four(oldPattern);
		if(a != -1){
			ans = a;
			return;
		}
		if(six(oldPattern) != -1){
			ans = 6;
			return;
		}
		if(ans == -1) {
			ans = 7;	
		}
	}
	
	public void output() throws IOException{
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("transform.out")));
		out.println(ans);
		out.close();
	}
	
	public char[][] getClone() {
		char c[][] = new char[n][n];
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)c[i][j] = oldPattern[i][j];
		return c;
	}
	
	public boolean equal(char[][] c) {
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++) {
				if(c[i][j] != newPattern[i][j]) {
					return false;
				}
			}
		return true;
	}
	
	public int one(char[][] oldPattern, int turn) {
		char c[][] = new char[n][n];
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++) {
				
					if(i == 0 && j == 0) {
						c[0][n - 1] = oldPattern[i][j];
					}else if(i == 0 && j == n-1) {
						c[n-1][n-1] = oldPattern[i][j];
					}else if(i == n-1 && j == n-1) {
						c[n-1][0]=oldPattern[i][j];
					}else if(i == n-1 && j == 0) {
						c[0][0] = oldPattern[i][j];
					}else
						c[j][(n-1)-i] = oldPattern[i][j];
			}}
		if(!equal(c)) {
			int prevTurn = turn;
			if(turn < 3) {
				turn = one(c, prevTurn + 1);
			}else {
				return -1;
			}
		}
		
		return turn;
	}
	
	public int four(char[][] oldPattern) {
		char[][] c = new char[n][n];
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++) {
				c[i][j] = oldPattern[i][(n-1)-j];
			}
		}
		if(!equal(c)) {
			int a = one(c, 1);
			if(a != -1) {
				return 5;
			}else{
				return -1;
			}
		}
		return 4;
	}
	public int six(char[][] c) {
		return (equal(c)?6:-1);
	}
	
}
