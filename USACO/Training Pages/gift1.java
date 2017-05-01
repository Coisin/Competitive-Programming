/*
ID: odwyero2
LANG: JAVA
TASK: gift1
*/

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class gift1 {
	
	public static void main(String args[]) {
		new gift1();
	}
	
	HashMap<String, person> people = new HashMap();
	int numPeople;
	
	ArrayList<String> names = new ArrayList();
	
	public gift1() {
		
		try {
			readIn();
			process();
			output();
		} catch(Exception e) {
			e.printStackTrace();
		}
		
	}
	
	public void readIn() throws IOException{
		Scanner in = new Scanner(new FileReader("gift1.in"));
		numPeople = in.nextInt();
		for(int i = 0;i<numPeople;i++) {
			String name = in.next();
			people.put(name, new person());
			names.add(name);
		}
		for(int i = 0;i<numPeople;i++) {
			String name = in.next();
			person p = people.get(name);
			
			int amount = in.nextInt();
			int quantity = in.nextInt();
			p.distrib = amount;
			for(int j = 0;j<quantity;j++) {
				p.friends.add(in.next());
			}
		}
	}
	
	public void process() {
		
		for(int i = 0;i<numPeople;i++) {
			String name = names.get(i);
			person p = people.get(name);
			
			if(p.distrib == 0 || p.friends.size() == 0)continue;
			int each = (p.distrib / p.friends.size());
			for(int j = 0;j<p.friends.size();j++) {
				person p2 = people.get(p.friends.get(j));
				p2.rec += each;
				p.given += each;
			}
		}
		
	}
	
	public void output() throws IOException{
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
		for(int i = 0;i<numPeople;i++) {
			person p = people.get(names.get(i));
			out.println(names.get(i) + " " + (p.rec - p.given));
		}
		out.close();
	}
	
}

class person {
	
	int rec=0, given=0;
	int distrib;
	ArrayList<String> friends = new ArrayList();
	
}