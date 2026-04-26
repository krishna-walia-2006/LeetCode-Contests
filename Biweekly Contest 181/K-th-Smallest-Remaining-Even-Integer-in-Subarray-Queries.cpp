class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& qs) {
        int n=nums.size();
        vector<int> p(n+1,0),res;
        for(int i=0;i<n;i++) p[i+1]=p[i]+!(nums[i]%2);
        for(auto& q:qs) {
            long long l=2,r=4e9,ans=4e9,k=q[2];
            while(l<=r) {
                long long m=l +(r-l)/2;
                int idx=upper_bound(nums.begin()+q[0],nums.begin()+q[1]+1,(int)min(m,2000000000LL)) - nums.begin();
                if(m/2 - (p[idx]-p[q[0]])>=k) ans=m,r=m-1;
                else l=m+1;
            }
            res.push_back(ans%2?ans+1:ans);
        }
        return res;
    }
};
