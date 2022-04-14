package uva;
import java.math.*;
import java.util.Scanner;
import java.lang.Math;
import static java.lang.System.*;

class Main {
	public static void main(String args[]){
		Scanner cin=new Scanner(in);
		BigDecimal[][] r=new BigDecimal[10][4];
		BigDecimal[] p=new BigDecimal[2];
		String tmp;
		int i,j,n=0,num=0,flag;
		while(true){
			tmp=cin.next();
			if(tmp.equals("*"))break;
			if(tmp.equals("c")){
				i=1;
				r[n][0]=null;
			}else{
				i=0;
			}
			for(;i<4;i++){
				tmp=cin.next();
				r[n][i]=new BigDecimal(tmp);
			}
			n++;
		}
		while(true){
			
			flag=0;
			tmp=cin.next();
			if(tmp.equals("9999.9"))flag++;
			p[0]=new BigDecimal(tmp);
			tmp=cin.next();
			if(tmp.equals("9999.9"))flag++;
			p[1]=new BigDecimal(tmp);
			if(flag==2)break;
			flag=0;
			for(i=0;i<n;i++){
				if(r[i][0]!=null&&p[0].compareTo(r[i][0])>0&&p[0].compareTo(r[i][2])<0&&p[1].compareTo(r[i][1])<0&&p[1].compareTo(r[i][3])>0){
					out.printf("Point %d is contained in figure %d\n",num+1,i+1);
					flag=1;
				}else if(r[i][0]==null){
					BigDecimal d=p[0].subtract(r[i][1]).multiply(p[0].subtract(r[i][1])).add(p[1].subtract(r[i][2]).multiply(p[1].subtract(r[i][2])));
					if(d.compareTo(r[i][3].multiply(r[i][3]))>=0)continue;
					out.printf("Point %d is contained in figure %d\n",num+1,i+1);
					flag=1;
				}
			}
			if(flag==0){
				if(num!=990)out.printf("Point %d is not contained in any figure \n",num+1);
				else out.printf("Point %d is not contained in any figure\n",num+1);
			}
			num++;
		}
	}
}
