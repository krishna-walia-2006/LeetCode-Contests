class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int minOperations(vector<int>& nums) {
        int operations = 0;

        for (int i = 0; i < nums.size(); i++) {
            bool needPrime = (i % 2 == 0);

            while (isPrime(nums[i]) != needPrime) {
                nums[i]++;
                operations++;
            }
        }

        return operations;
    }
};
