import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class UVa_324 {
	
	public static void main(String args[]) {
		new UVa_324();
	}
	
	public UVa_324() {
		Scanner input = new Scanner(System.in);
		int number = input.nextInt();
		
		while(number != 0) {
			
			
			String factAsString = factorial(BigInteger.valueOf(number)).toString();
			
			ArrayList<Integer> numbers = new ArrayList();
			for(int i = 0;i<factAsString.length();i++) {
				int currentDigit = Character.getNumericValue(factAsString.charAt(i));
				numbers.add(currentDigit);
			}
			
			System.out.printf("%d! --\n", number);
			System.out.printf("    (0)  %3d    (1)  %3d    (2)  %3d    (3)  %3d   (4)  %3d\n", Collections.frequency(numbers, 0), Collections.frequency(numbers, 1), Collections.frequency(numbers, 2), Collections.frequency(numbers, 3), Collections.frequency(numbers, 4));
			System.out.printf("    (5)  %3d    (6)  %3d    (7)  %3d    (8)  %3d   (9)  %3d\n", Collections.frequency(numbers, 5), Collections.frequency(numbers, 6), Collections.frequency(numbers, 7), Collections.frequency(numbers, 8), Collections.frequency(numbers, 9));
			
			number = input.nextInt();
			
		}
		
	}
	
	public BigInteger factorial(BigInteger n) {
		if(n.equals(BigInteger.ONE)) {
			return BigInteger.ONE;
		}
		return n.multiply(factorial(n.subtract(BigInteger.ONE)));
	}
	
}
