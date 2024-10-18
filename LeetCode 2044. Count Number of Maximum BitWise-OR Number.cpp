class Solution {
//Solution: Using prefixSum + backTracking O(2^N)
public:
    #define boots() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    void backTrack(vector<int>&nums,int i,int &cnt,int target,vector<int>&temp){
        if(i==nums.size()){
            int calc = 0;
            for(auto &it : temp) calc|=it;
            if(calc==target) cnt++;
            return;
        }
        temp.push_back(nums[i]);
        backTrack(nums,i+1,cnt,target,temp);
        temp.pop_back();
        backTrack(nums,i+1,cnt,target,temp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        boots();
        int n = nums.size();
        vector<int>prefix(n),temp;
        temp.clear();
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]|nums[i];
        }
        int target = prefix.back();
        int cnt = 0;
        backTrack(nums,0,cnt,target,temp);
        return cnt;
    }
};
// 011
// 101
// 111
// 3 2 1 5
// prefix[0] = 3
// prefix[0]|nums[1] -> prefix[1] = 011  = 3
// prefix[1]|nums[2] -> prefix[2] = 011 = 3
// prefix[2]|nums[3] -> prefix[3] = 111 = 7
