package JAVA;
import java.util.Scanner;
import java.math.*;
import java.lang.Math;
import static java.lang.System.*;

public class c188 {
	public static Scanner cin=new Scanner(in);
	public static void main(String[] args) {
		BigInteger data[][]=new BigInteger[201][201];//head sum
		BigInteger ans[]=new BigInteger[201];
		for(int i=0;i<=200;i++){
			ans[i]=BigInteger.ZERO;
			for(int j=0;j<=200;j++)data[i][j]=BigInteger.ZERO;
		}
		ans[0]=BigInteger.ONE;
		data[0][0]=BigInteger.ONE;
		data[1][1]=BigInteger.ONE;
		for(int i=2;i<=200;i++){//sum
			for(int j=i;j>=1;j--){//head
				for(int k=0;k<=j;k++){
					data[j][i]=data[j][i].add(data[k][i-j]);
				}
			}
		}
		for(int i=1;i<=200;i++){
			for(int j=1;j<=i;j++)ans[i]=ans[i].add(data[j][i]);
		}
		int n;
		while(cin.hasNext()){
			n=cin.nextInt();
			out.println(ans[n]);
		}
	}

}
