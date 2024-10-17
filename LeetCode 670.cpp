class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        vector<int>visit(10,-1);
        int cnt = 0;
        for(auto it : temp){
            visit[it-'0'] = cnt;
            cnt++;
        }
        for(int i=0;i<temp.size();++i){
            for(int j=9;j>temp[i]-'0';--j){
                if(visit[j]>i&&temp[visit[j]]!=temp[i]){
                    swap(temp[visit[j]],temp[i]);
                    return stoi(temp);
                }
            }
        }
        return num;
    }
};
// 8192
// 9182
// 9973
// 9793
