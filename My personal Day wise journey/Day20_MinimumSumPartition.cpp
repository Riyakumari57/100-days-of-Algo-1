
class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
        int sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        int dp[n+1][sum+1];
        //if sum = 0 then yeah we did it
        for(int i=0;i<=n;i++)dp[i][0] = 1;
        for(int i=1;i<=sum;i++)dp[0][i] = 0;
        
        for(int i=1;i<=sum;i++){
            for(int j=1;j<=n;j++){
                //ignore case
                if(arr[j-1]>i)
                   dp[j][i] = dp[j-1][i];
                if(arr[j-1]<=i){
                    dp[j][i] = dp[j-1][i] + dp[j-1][i- arr[j-1]];
                }
            }
        }
           //last row of this table if answer for us
   for(int i=0;i<=n;i++){
       for(int j=0;j<=sum;j++){
           cout<<dp[i][j]<<" ";
       }
       cout<<endl;
   }
   int ans = INT_MAX;
   for(int i=0;i<=sum/2;i++){
     if(dp[n][i]){
         ans = min(ans,sum-2*i);
     }    
   }
   return ans;
	} 
};
