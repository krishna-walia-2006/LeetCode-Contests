class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> temp(n,vector<int> (2,0));
        temp[0][0]=nums[0];
        for(int i=1;i<n;i++) 
            temp[i][0]=max(temp[i-1][0],nums[i]);
        
        temp[n-1][1]=nums[n-1];
        for(int i=n-2;i>=0;i--) 
            temp[i][1]=min(temp[i+1][1],nums[i]);
        for(int i=0;i<n;i++) {
            int score=temp[i][0]-temp[i][1];
            if(score<=k) {
                return i;
            }
        }
        return -1;
    }
};
