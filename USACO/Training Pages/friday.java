/*
ID: odwyero2
LANG: JAVA
TASK: friday
*/


import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class friday {
	
	public static void main(String args[]) {
		new friday();
	}
	
	public friday() {
		try {
			readIn();
			process();
			output();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	int[] numDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int currentYear = 1900;
	int currentMonth = 0;
	int currentDay = 0;
	
	int[] frequency = {0, 0, 0, 0, 0, 0, 0};
	
	int n;
	
	public void readIn() throws IOException{
		Scanner in = new Scanner(new FileReader("friday.in"));
		n = in.nextInt();
	}
	
	public void process() {
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<12;j++) {
				
				frequency[getDay(currentDay, 13)]++;
				if(j == 1 && isLeap(currentYear + i)) {
					currentDay = getDay(currentDay, 29);
				} else {
					currentDay = getDay(currentDay, numDays[j]);
				}
				
			}
		}
	}
	
	public void output() throws IOException{
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("friday.out")));
		out.print(frequency[6] + " ");
		for(int i = 0;i<frequency.length-2;i++) {
			out.print(frequency[i] + " ");
		}
		out.println(frequency[5]);
		out.close();
	}
	
	public boolean isLeap(int year) {
		if(year % 100 == 0)return (year % 400 == 0);
		return (year % 4 == 0);
	}
	
	public int getDay(int orig, int elapsed) {
		elapsed %= 7;
		orig += elapsed;
		if(orig >= 7 )orig %= 7;
		return orig;
	}
	
}
