class Solution{
public:
    int equalPartition(int N, int arr[])
    {
       int totalSum = 0;
       for(int i=0;i<N;i++){
           totalSum+=arr[i];
       }
       if(totalSum%2==1)return 0; // not possible for odd total sum
       bool dp[(totalSum)/2+1][N+1];
       //if n == 0 then its false
       for(int i=0;i<=totalSum/2;i++)dp[i][0] = false;
       for(int i=0;i<=N;i++)dp[0][i] = true;
       
       for(int i=1;i<=totalSum/2;i++){
           for(int j=1;j<=N;j++){
              
               if(arr[j-1]<=i){
                   dp[i][j] = dp[i][j-1] || dp[i - arr[j-1]][j-1];
               }else  dp[i][j] = dp[i][j-1];
           }
       }
       return dp[totalSum/2][N];
       
    }
};
