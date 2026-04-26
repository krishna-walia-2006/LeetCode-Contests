class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums;
        vector<int> rightMax(n,INT_MIN),leftMax(n,INT_MIN),ans;
        ans.push_back(nums[0]);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++) {
            leftMax[i]=maxi;
            maxi=max(maxi,nums[i]);
        }
        maxi=INT_MIN;
        for(int i=n-1;i>=0;i--) {
            rightMax[i]=maxi;
            maxi=max(maxi,nums[i]);
        }
        for(int i=1;i<n-1;i++) {
            if(nums[i]>leftMax[i] || nums[i]>rightMax[i]) ans.push_back(nums[i]);
        }
        ans.push_back(nums[n-1]);
        return ans;
    }
};
