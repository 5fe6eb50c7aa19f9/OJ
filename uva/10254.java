package uva;
import java.math.*;
import java.util.Scanner;
import java.lang.Math;
import static java.lang.System.*;

class Main {
	public static Scanner cin=new Scanner(in);
	public static void main(String args[]){
		BigDecimal[] dp3=new BigDecimal[10001];
		BigDecimal[] dp4=new BigDecimal[10001];
		BigDecimal two=new BigDecimal("2"),tmp;
		int t,n,i,j,k;
		dp3[0]=BigDecimal.ZERO;
	    for(i=1;i<=10000;i++){
	        dp3[i]=dp3[i-1].multiply(two).add(BigDecimal.ONE);
	    }
	    dp4[0]=BigDecimal.ZERO;
	    for(i=1;i<=10000;i++){
	        dp4[i]=dp3[i];
	        for(j=i-1;j>=0;j--){
	        	tmp=dp4[j].multiply(two).add(dp3[i-j]);
	        	if(dp4[i].compareTo(tmp)>=0){
	        		dp4[i]=tmp;
	        	}else{
	        		break;
	        	}
	        }
	    }
	    while(cin.hasNext()){
	    	n=cin.nextInt();
	    	out.println(dp4[n]);
	    }
	}
}
