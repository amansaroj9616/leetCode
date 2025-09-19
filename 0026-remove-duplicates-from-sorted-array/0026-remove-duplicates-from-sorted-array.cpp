class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // sort(nums.begin(), nums.end());
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
            
        }
        return i+1;

    }
};