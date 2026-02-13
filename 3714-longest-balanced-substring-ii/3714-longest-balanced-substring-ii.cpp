class Solution {
public:

    int helper(string &s , int ch1 , int ch2 ){
        int n = s.length();
        unordered_map<int, int> diffMap;
        int maxL = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }

            if(s[i] == ch1)
                count1++;
            if(s[i] == ch2)
                count2++;

            if(count1 == count2) {
                maxL = max(maxL, count1+count2);
            }

            int diff = count1 - count2;
            if(diffMap.count(diff)) {
                maxL = max(maxL, i - diffMap[diff]);
            } else {
                diffMap[diff] = i;
            }
        }
        
        return maxL;

    }
    int longestBalanced(string s) {
        int n=s.size();
        int maxLength=0;
        int count=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                maxLength=max(maxLength,count);
                count=1;
            }
        
        }
        maxLength=max(maxLength,count);

        maxLength=max(maxLength, helper(s,'a','b'));
        maxLength=max(maxLength,helper(s,'a','c'));
        maxLength=max(maxLength, helper(s,'b','c'));

        int countA=0;
        int countB=0;
        int countC=0;
        unordered_map<string , int>diffMap;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                countA++;
            }
            if(s[i]=='b'){
                countB++;
            }
            if(s[i]=='c'){
                countC++;
            }

            if(countA == countB && countA==countC){
                maxLength=max(maxLength, countA+countB+countC);
            }
         int diffAB = countA - countB;
            int diffAC = countA - countC;

            string key = to_string(diffAB) + "_" + to_string(diffAC); 

            if(diffMap.count(key)) {
                maxLength = max(maxLength, i - diffMap[key]);
            } else {
                diffMap[key] = i;
            }
        }

        return maxLength;
    }
};