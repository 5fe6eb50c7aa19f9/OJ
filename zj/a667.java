import java.math.*;
import java.util.Scanner;
import java.lang.Math;
import static java.lang.System.*;

class JAVA {
	public static void main(String args[]){
		Scanner cin=new Scanner(in);
		BigDecimal a,b;
		while(cin.hasNext()){
			a=new BigDecimal(cin.next());
			b=new BigDecimal(cin.next());
			out.printf("%s    %s\n",a.divide(b,0,RoundingMode.DOWN),a.remainder(b));
		}
	}
}
