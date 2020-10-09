// problem https://leetcode.com/problems/target-sum
// bruteForce approach
class Solution {
public:
    int count=0;
    int findTargetSumWays(vector<int>& nums, int S) {
        calc(nums,0,0,S);
        return count;
    }
    void calc(vector<int> &nums,int i,int sum,int target){
        if(i == nums.size()){
            if(sum==target)count++;
        }
        else {
            calc(nums,i+1,sum+nums[i],target);
            calc(nums,i+1,sum-nums[i],target);
        }
    }
};


// recursion and memoisation
class Solution {
public:
    int count=0;
    int memo[25][3002];
    int findTargetSumWays(vector<int>& nums, int S) {
        for(int i=0;i<25;i++)
            for(int j=0;j<3002;j++)
                memo[i][j] = INT_MIN;
        int ans = calc(nums,0,0,S);
        return ans;
    }
    int calc(vector<int> &nums,int i,int sum,int target){
        if(i == nums.size()){
            if(sum==target)
            {
                return 1;
            }else return 0;

        }else 
        {
           if(memo[i][sum+1000]!=INT_MIN)
            return memo[i][sum+1000];
            
           return memo[i][sum+1000] = calc(nums,i+1,sum+nums[i],target) + 
               calc(nums,i+1,sum-nums[i],target);
         
        }   
    }
};
