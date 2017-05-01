import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/*
ID: odwyero2
LANG: JAVA
TASK: milk2
*/

public class milk2 {
	
	public static void main(String args[]) {
		new milk2();
	}
	
	public milk2() {
		try {
			readIn();
			process();
			output();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	int n;
	int[] start, end;
	int maxDur = 0, maxAbs = 0;
	
	public void readIn() throws IOException{
		Scanner in = new Scanner(new FileReader("milk2.in"));
		n = in.nextInt();
		start = new int[n];
		end = new int[n];
		for(int i = 0;i<n;i++) {
			start[i] = in.nextInt();
			end[i] = in.nextInt();
		}
	}
	
	public void process() {
		
		Arrays.sort(start);
		Arrays.sort(end);
		
		for(int i = 0;i<n;i++) {
			int starting = start[i];
			int ending = end[i];
			for(int j = 0;j<n;j++) {
				int nStart = start[j];
				int nEnd = end[j];
				if(nStart <= starting && nEnd >= starting) {
					starting = nStart;
				}
				if(nEnd >= ending && nStart <= ending) {
					ending = nEnd;
				}
			}
			if(maxDur < ending - starting)maxDur = ending - starting;
		}
		
		int startC = 0;
		int endC = 0;
		
		while(startC < n) {
			if(start[startC] <= end[endC]) {
				startC++;
			}else{
				startC--;
				if(startC == endC) {
					if(maxAbs < start[startC+1] - end[endC]) {
						maxAbs = start[startC+1] - end[endC];
					}
				}
				endC++;
			}
		}
	}
	
	public void output() throws IOException{
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));
		out.println(maxDur + " " + (maxAbs));
		out.close();
	}	
}