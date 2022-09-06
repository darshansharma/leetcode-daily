// question link - https://leetcode.com/problems/numbers-with-same-consecutive-differences/submissions/


class Solution {
public:
    vector<int> res;
    int power = 1;
    void dfs(int x, int n, int k) {
        // cout<<"( "<<x<<", "<<n<<", "<<k<<" )"<<endl;
        if(n == 0) {
            res.push_back(x);
            return;
        }
        
        for(int i=0; i<=9; i++) {
            int num = x%10 - i;
            num = abs(num);
            if (num == k){
                dfs(x*pow(10,1)+i, n-1, k); 
            }
            
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        int num = 0;
        for(int i=1; i<10; i++) {
                dfs(i, n-1, k);
        }
        
        for(int i=0; i<res.size(); i++) {
            cout<<res[i]<<" ";
        }
        return res;
    }
};
