import java.math.*;
import java.util.Scanner;
import java.lang.Math;
import static java.lang.System.*;

class Main {
	public static void main(String args[]){
		int n;
		String tmp; 
		BigDecimal data,ans,delta;
		BigDecimal two=new BigDecimal("2");
		BigDecimal error=new BigDecimal("0.1");
		Scanner cin=new Scanner(in);
		n=cin.nextInt();
		while(n-->0){
			tmp=cin.next();
			data=new BigDecimal(tmp);
			ans=data.divide(two,0,RoundingMode.DOWN).add(BigDecimal.ONE);
			delta=ans.subtract(data.divide(ans,4,4)).divide(two,4,4);
			while(delta.compareTo(error)>0){
				ans=ans.subtract(delta);
				delta=ans.subtract(data.divide(ans,4,4)).divide(two,4,4);
			}
			out.printf("%s",ans.setScale(0,RoundingMode.DOWN));
			out.printf("\n");
			if(n!=0)out.printf("\n");
		}
	}
}
