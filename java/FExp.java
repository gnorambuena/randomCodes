public class FExp{
    static long[][] mult(long[][] a,long[][] b){
		long[][] c = new long[a.length][b[0].length];
		for(int i = 0 ; i < a.length ; i++){
			for(int j = 0 ; j < b[0].length ; j++){
				long sum = 0;
				for(int k = 0 ; k < b.length ; k++){
					sum += a[i][k]*b[k][j];
				}
				c[i][j] = sum;
			}
		}
		return c;
	}
	static long[][] fastExp(long[][] a, int exp){
		long[][][] dp = new long[exp+1][a.length][a[0].length];
		return internalfastExp(a,exp,dp);
	}
	static long[][] internalfastExp(long[][] a, int exp, long[][][] dp){
		long[][] nullmatrix = new long[a.length][a[0].length];
		if(exp==1)return a;
		if(!java.util.Arrays.deepEquals(dp[exp],nullmatrix))return dp[exp];
		else{
			//impar
			if(exp % 2 == 1){
				dp[exp]=mult(internalfastExp(a,exp/2,dp),internalfastExp(a,exp/2,dp));
				dp[exp]=mult(dp[exp],a);
				return dp[exp];
			}
			//par
			else{
				dp[exp]=mult(internalfastExp(a,exp/2,dp),internalfastExp(a,exp/2,dp));
				return dp[exp];
			}
		}
	}
	public static void main(String[] args){
		long[][] b = new long[2][2];
		long[][] in = new long[2][1];
		b[0][0] = 1 ;
		b[0][1] = 1 ;
		b[1][0] = 1 ;
		b[1][1] = 0 ;
		in[0][0] = 1;
		long[][] c = mult(fastExp(b,91),in); 

		for(int i = 0 ; i < c.length ; i++){
			for(int j = 0 ; j < c[0].length ; j++)
				System.out.print(c[i][j] + " ");
			System.out.println();
		}
	}
}