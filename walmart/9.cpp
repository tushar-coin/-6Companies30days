 class Solution {
public:

int helper(int left, int right,  vector<vector<int>>& dp)      
{
    if(left >= right)
        return 0;
    
    if(dp[left][right])
        return dp[left][right];
    
    int res = INT_MAX;
    for(int i =left;i <= right; i++ )
        res = min(res, i+max(helper(left, i-1,dp),helper(i+1, right,dp)));
    
    dp[left][right] = res;
    return res;
}
int getMoneyAmount(int n) {
    
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    
    return helper(1, n, dp);
    
}
};