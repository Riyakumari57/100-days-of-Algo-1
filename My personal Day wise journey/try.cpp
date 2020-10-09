#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

//recursive method
int lcs(string s1,string s2,int s1len,int s2len){
    if(s1len ==0 || s2len == 0)return 0;
    if(s1[s1len-1] == s2[s2len -1]){
        if(dp[s1len-1][s2len-1]!=-1) return dp[s1len-1][s2len-1];
         return dp[s1len][s2len] = lcs(s1,s2,s1len-1,s2len-1)+1;
    }
    else {
        if(dp[s1len][s2len-1] !=-1 && dp[s1len-1][s2len]!=-1)
           return max(dp[s1len][s2len-1], dp[s1len-1][s2len]);
        return dp[s1len][s2len] = max(lcs(s1,s2,s1len-1,s2len),lcs(s1,s2,s1len,s2len-1));
        }
}


int lcsDP(string s1,string s2,int s1len,int s2len){
    for(int i=0;i<1000;i++)dp[i][0] = 0;
    for(int i=0;i<1000;i++)dp[0][i] = 0;

    for(int i=0;i<=s1len;i++){
        for(int j=0;j<=s2len;j++){
            if(i==0 || j==0){dp[i][j] = 0;continue;}
            if(s1[i-1]== s2[j-1])dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[s1len][s2len];
}

int main(){
    for(int i=0;i<1000;i++) for(int j=0;j<1000;j++) dp[i][j] = -1;
    string s1,s2;
    cout<<"Enter first string\n";
    cin>>s1;
    cout<<"Enter secind string\n";
    cin>>s2;
    int ans = lcsDP(s1,s2,s1.length(),s2.length());
    cout<<"LCS is "<<ans<<endl;

}