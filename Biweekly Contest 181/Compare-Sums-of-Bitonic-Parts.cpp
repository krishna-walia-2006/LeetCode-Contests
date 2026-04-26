class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size(),i=0;
        long long sI=0,sD=0;
        while(i<n-1 && nums[i]<=nums[i+1]) {
            sI+=nums[i];
            i++;
        }
        sI+=nums[i];            
        while(i<n-1 && nums[i]>=nums[i+1]) {
            sD+=nums[i];
            i++;
        }
        sD+=nums[i];
        if(sD==sI) return -1;
        else if(sI>sD) return 0;
        else return 1; 
    }
};
