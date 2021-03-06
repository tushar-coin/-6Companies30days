class Solution {
public:
    bool isCapable(vector<int>& v, int m, int total){
        int splits = 0, sum = 0;
        for(auto it : v){
            if(it > total) return false;
            
            if(sum+it > total){
                splits++;
                sum = it;
            } else {
                sum += it;
            }
        }
        
        return splits < m;
    }
	
    int splitArray(vector<int>& v, int m) {
        
        int l = 0, r = INT_MAX;
        int mid, ans;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(isCapable(v, m, mid)) {    
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return ans;
    }
};
