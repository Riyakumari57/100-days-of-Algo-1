//using recursion
class Solution{
public:

    int knap(int N,int W,int val[],int wt[]){
         if(N==0 || W==0)return 0;
         if(wt[N]>W)return knap(N,W,val,wt);
         return max(val[N]+knap(N, W - wt[N],val,wt),knap(N-1,W,val,wt));
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return knap(N-1,W,val,wt);
    }
};




//using dp
class Solution{
public:

    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[W+1];
        memset(dp,0,sizeof dp);
        
        for(int i=0;i<=W;i++)
          for(int j=0;j<N;j++){
              if(wt[j]<=i) dp[i] =  max(dp[i], dp[i- wt[j]]+val[j]);
          }
        return dp[W];
    }
};
