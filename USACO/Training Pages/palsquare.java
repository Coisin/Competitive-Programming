import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
ID: odwyero2
LANG: JAVA
TASK: palsquare
*/

public class palsquare {
	
	public static void main(String args[]) {
		new palsquare();
	}
	
	public palsquare(){
		try {
			readIn();
			process();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	int base;
	
	public void readIn() throws IOException{
		Scanner in = new Scanner(new FileReader("palsquare.in"));
		base = in.nextInt();
	}
	
	public void process() throws IOException {
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));
		for(int i = 1;;i++) {
			if(i > 300)break;
			String product = Integer.toString(i * i,base);
			if(product.equals(new StringBuilder(product).reverse().toString())) {
				out.println(Integer.toString(i, base).toUpperCase() + " " + product.toUpperCase());
			}
		}
		out.close();
	}
	
}
