#include<bits/stdc++.h>
#define puneesh int
using namespace std;


//recursive  approach
int solve(vector<int> &arr,int target,int n){
    if(n==0 && target!=0)return 0;
    if(target==0) return 1;
    if(target < arr[n-1]) return solve(arr,target,n-1);
    return solve(arr,target - arr[n-1],n) + solve(arr, target,n-1);
}

//using bottom up aproach
int solveBU(vector<int> &arr, int target, int n){
    int dp[target+1][n+1];
    for(int i=0;i<=n;i++) dp[0][i] = 1;
    for(int j=1;j<=target;j++) dp[j][0] = 0;
    
    for(int i=1;i<=target;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i][j-1];
            if(arr[j-1] <= i)
              dp[i][j] = dp[i-arr[j-1]][j] + dp[i][j-1];
        }
    }
    return dp[target][n];
}

int main(){
    int n;
    cout<<"Enter number of coins you have\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter coins you have\n";
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Enter amout you have to pay\n";
    int target;
    cin>>target;
    unsigned long long int maxWays = solveBU(arr,target,arr.size());
    cout<<maxWays<<"\n";
    return 0;
}