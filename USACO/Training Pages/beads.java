import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/*
ID: odwyero2
LANG: JAVA
TASK: beads
*/

public class beads {
	
	public static void main(String args[]) {
		new beads();
	}
	
	public beads() {
		try{
			readIn();
			process();
			output();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	int n;
	char[] beads;
	int max = 0;
	
	public void readIn() throws IOException{
		Scanner in = new Scanner(new FileReader("beads.in"));
		n = in.nextInt();
		beads = in.next().toCharArray();
	}
	
	public void process() {
		int splittingPoint = beads.length;
		int startingPoint = -1;
		
		int group1 = 0;
		int initialBead = -1;
		
		
		
		for(int i = 0;i<beads.length;i++) {
			if(beads[i] != 'w') {
				initialBead = i;
				break;
			}
		}
		if(initialBead == -1) {
			max = beads.length;
			return;
		}
		boolean changed = false;
		for(int i = 0;i<beads.length;i++)if(beads[i] != 'w' && beads[i] != beads[initialBead]){
			changed = true;
			break;
		}
		if(!changed){
			max = beads.length;
			return;
		}
		int group1Offset = 0;
		if(beads[initialBead] == beads[beads.length - 1] || beads[beads.length - 1] == 'w') {
			for(int j = beads.length - 1; j >= 0; j--) {
				if(beads[j] != beads[initialBead] && beads[j] != 'w') {
					splittingPoint = j + 1;
					break;
				} else {
					if(beads[j] == 'w') {
						group1Offset++;
					}else group1Offset = 0;
					group1++;
				}
			}
		}
		char currentBead = beads[initialBead];
		for(int i = 0;i<splittingPoint;i++) {
			if(beads[i] == currentBead || beads[i] == 'w') {
				group1++;
			}else {
				startingPoint = i;
				currentBead = beads[i];
				break;
			}
		}
		
		int pastGroup = group1;
		int currentGroup = 0;
		
		int offset = 0;
		int pastOffset = 0;
		
		for(int i = startingPoint; i < splittingPoint + group1Offset; i++) {
			if(beads[i] == currentBead || beads[i] == 'w') {
				currentGroup++;
				if(beads[i] == 'w')offset++;
				else offset = 0;
			} else {
				if((currentGroup + pastGroup) - pastOffset > max) {
					max = (currentGroup + pastGroup) - pastOffset;
				}
				
				currentBead = beads[i];
				pastGroup = currentGroup;
				currentGroup = 1 + offset;
				pastOffset = offset;
				offset = 0;
			}
		}
		//System.out.println(pastGroup);
		if((currentGroup + pastGroup) - pastOffset > max) {
			max = (currentGroup + pastGroup) - pastOffset;
		}
		if(currentGroup + group1 > max)max = (currentGroup + group1)-group1Offset;
		
	}
	
	public void output() throws IOException{
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));
		out.println(max);
		out.close();
	}
	
}
