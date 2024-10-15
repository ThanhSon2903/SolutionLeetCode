class Solution {
#define nhanh() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
public:
    int maximumLength(string s) {
        nhanh();
        int n = s.size(),ans = -1;
        vector<vector<int>>dp(26,vector<int>(n+1,0));
        char c = s[0];
        int cnt = 1;
        dp[c-'a'][cnt] = 1;//khởi tạo ký tự đầu tiên với cnt bằng 1 và tần suất xuất hiện bằng 1.
        for(int i=1;i<n;++i){
            char tmp = s[i];
            if(tmp==c){
                dp[tmp-'a'][++cnt]+=1;//nếu tmp==c->tăng cnt và tằng tần suất xuất hiện 
            }
            else{
                cnt = 1;
                dp[tmp-'a'][cnt]+=1;
                c = tmp;
            }
        }
        for(int i=0;i<26;++i){
            int total = 0;
            for(int j=n;j!=0;--j){
                total+=dp[i][j];
                if(total>=3){
                    ans = max(ans,j);
                    break;
                }
            }
        }
        return ans;
    }
};
//dp[char-'a'][len] = freq
// dp[a][1] = 3;
// dp[b][1] = 2;
// dp[c][1] = 1;
