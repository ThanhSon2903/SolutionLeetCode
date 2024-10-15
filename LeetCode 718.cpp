class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        if(nums1==nums2) return nums1.size();
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));
        int n = nums1.size(),m=nums2.size(),ans = INT_MIN;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(i==0||j==0){
                    dp[i][j] = 0;
                }
                else{
                    if(nums1[i-1]==nums2[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }   
};
