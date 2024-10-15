class Solution {
public:
    int calc(vector<int>&nums,int l,int r,vector<vector<int>>&dp){
        if(l==r) return nums[l];//base Case
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int pickLeft = nums[l] - calc(nums,l+1,r,dp);
        int pickRight = nums[r] - calc(nums,l,r-1,dp);
        dp[l][r] = max(pickLeft,pickRight);
        return dp[l][r];
    }
    bool predictTheWinner(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = calc(nums,0,n-1,dp);
        if(ans>=0) return true;
        return false;
    }
};