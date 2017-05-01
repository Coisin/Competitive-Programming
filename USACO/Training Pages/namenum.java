import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

/*
ID: odwyero2
LANG: JAVA
TASK: namenum
*/

public class namenum {
	
	public static void main(String args[]) {
		new namenum();
	}
	
	public namenum() {
		try {
			readIn();
			process();
			output();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	long n;
	HashMap<Integer, ArrayList<String>> map = new HashMap();
	
	char[][] phone = {
			{'a','b','c'},
			{'d','e','f'},
			{'g','h','i'},
			{'j','k','l'},
			{'m','n','o'},
			{'p','r','s'},
			{'t','u','v'},
			{'w','x','y'},};
	
	static LinkedList<String> possibleNames = new LinkedList();
	
	public void readIn() throws IOException {
		Scanner in = new Scanner(new FileReader("namenum.in"));
		Scanner nameIn = new Scanner(new FileReader("dict.txt"));
		
		n = in.nextLong();
		for(int i = 0;i<phone.length;i++){
			for(int j = 0;j<phone[i].length;j++) {
				map.put((int)phone[i][j], new ArrayList());
			}
		}
		while(nameIn.hasNext()) {
			String name = nameIn.next().toLowerCase();
			possibleNames.add(name);
		}
	}
	
	public void process() throws IOException{
		
		String n = Long.toString(this.n);
		
		for(int i = 0;i<possibleNames.size();i++) {
			String name = possibleNames.get(i);
			
			if(name.length() != n.length()) {
				possibleNames.set(i, "XXXXX");
				//out.println(possibleNames.contains(name));
				continue;
			}
			for(int counter = 0;counter<n.length();counter++) {
				int num = (int)Long.parseLong(""+n.charAt(counter)) - 2;
				char[] pLetters = phone[num];
				boolean included = false;
				
				for(int j=0;j<pLetters.length;j++) {
					if((int)pLetters[j] == (int)name.charAt(counter)){
						included = true;
						break;
					}
				}
				if(!included) {
					possibleNames.set(i, "XXXXX");
					break;
				}
			}
		}
	}
	
	public void output() throws IOException {
		PrintWriter out= new PrintWriter(new BufferedWriter(new FileWriter("namenum.out")));
		boolean found = false;
		for(int i = 0;i<possibleNames.size();i++){
				if(!possibleNames.get(i).equals("XXXXX")){
					found = true;
					out.println(possibleNames.get(i).toUpperCase());
				}
			}
		if(!found)out.println("NONE");
		
		out.close();
	}
	
}
