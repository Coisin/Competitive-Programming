import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
ID: odwyero2
LANG: JAVA
TASK: dualpal
*/

public class dualpal {
	
	public static void main(String args[]) {
		new dualpal();
	}
	
	public dualpal() {
		try {
			readIn();
			process();
			output();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	int n, s;
	
	public void readIn() throws IOException {
		Scanner  in = new Scanner(new FileReader("dualpal.in"));
		n = in.nextInt();
		s = in.nextInt();
	}
	
	public void process() throws IOException{
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dualpal.out")));
		int counter = 0;
		for(int i = s + 1;;i++) {
			if(counter == n)break;
			int baseCounter = 0;
			for(int k = 2;k<=10;k++) {
				String inBase = Integer.toString(i, k);
				if(inBase.equals(new StringBuilder(inBase).reverse().toString())) {
					baseCounter++;
					if(baseCounter == 2) {
						out.println(i);
						counter++;
						break;
					}
				}
			}
		}
		out.close();
	}
	
	public void output() throws IOException {
		
	}
	
}
