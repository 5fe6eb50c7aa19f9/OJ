import java.math.*;
import java.util.Scanner;
import java.lang.Math;
import static java.lang.System.*;

class Main {
	public static void main(String args[]){
		Scanner cin=new Scanner(in);
		BigDecimal a,b;
		int n=cin.nextInt();;
		while(n-->0){
			a=new BigDecimal(cin.next());
			b=new BigDecimal(cin.next());
			out.println(a.subtract(b));
		}
	}
}
