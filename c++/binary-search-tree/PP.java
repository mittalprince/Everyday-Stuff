import java.util.*;
import java.math.BigInteger;

public class array
{
    public static Scanner scn = new Scanner(System.in);

    public static void totalcost(long[] arr, long[] cost){

        long[][] strg = new long[arr.length][arr.length];

        
        long ans = 0;

        for(int g=0;g<arr.length;g++){

            for(int i=0;i<arr.length -g;i++){

                int j= i+g;

                if(g==0){
                    strg[i][j] = (long)0;
                }
                else{
                    strg[i][j] = Math.abs(arr[i]-arr[j]) * (Math.max(cost[i],cost[j]));

                    ans += strg[i][j];
                }
            }
        }

        System.out.println(ans % 1000000007);
    }

    public static void main(String[] args){
        
        long t= scn.nextLong();

        for(int i=0;i<t;i++){

            int q= scn.nextInt();

            long[] arr= new long[q];

            for(int k=0;k<q;k++){
                arr[k]= scn.nextLong();
            }

            long[] cost= new long[q];

            for(int j=0;j<q;j++){
                cost[j]= scn.nextLong();
            }

            totalcost(arr,cost);


            
        }
    } 
}