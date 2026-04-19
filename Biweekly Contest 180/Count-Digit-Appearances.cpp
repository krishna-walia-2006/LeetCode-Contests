class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int d) {
        int count=0;
        for(int n:nums) {
            for(int temp=abs(n);temp>0;temp/=10) {
                if(temp%10==d) count++;
            }
        }
        return count;
    }
};
