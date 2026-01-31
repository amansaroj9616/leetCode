class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n =letters.size();
        int left=0;
        int right=n-1;
        int first_index=-1;
        while(left<=right){
            int mid = left+(right-left);
            if(letters[mid]>target){
                first_index=mid;
                right=mid-1;

            }
            else{
                left=mid+1;
            }
        }
        if(first_index==-1){
            return letters[0];
        }
       return letters[first_index];


        
    }
};