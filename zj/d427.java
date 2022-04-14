import java.math.*;
import java.util.Scanner;
import java.lang.Math;
import static java.lang.System.*;

class JAVA{
	public static void main(String args[]){
		String tmp; 
		BigDecimal data,ans,delta;
		BigDecimal two=new BigDecimal("2");
		BigDecimal error=new BigDecimal("0.1");
		error=error.movePointLeft(55);
		Scanner cin=new Scanner(in);
		while(cin.hasNext()){
			tmp=cin.next();
			data=new BigDecimal(tmp);
			ans=data.divide(two,0,RoundingMode.DOWN).add(BigDecimal.ONE);
			delta=ans.subtract(data.divide(ans,60,4)).divide(two,60,4);
			while(delta.compareTo(error)>0){
				ans=ans.subtract(delta);
				delta=ans.subtract(data.divide(ans,60,4)).divide(two,60,4);
			}
			out.printf("%s\n",ans.setScale(50,RoundingMode.DOWN));
		}
	}
}
