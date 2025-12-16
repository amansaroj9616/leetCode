class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        vector<int> rotated(nums.size(), 0);
        int n = nums.size();
        k = k % n;
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = rotated[i];
        }
    }
};