class Solution {
public:

     int BinarySearch(vector<int>& nums, int st, int end, int target) {
        if (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                return BinarySearch(nums, mid + 1, end, target);
            } else {
                return BinarySearch(nums, st, mid - 1, target);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return BinarySearch(nums, 0, nums.size() - 1, target);
    }
};