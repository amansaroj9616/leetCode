class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        for (int x : nums) totalSum += x;

        // Difference (left - right) is even  <=>  totalSum is even.
        if (totalSum % 2 != 0) return 0;

        // Valid split points are between elements: 0..n-2
        return n > 0 ? n - 1 : 0;
    }
};
