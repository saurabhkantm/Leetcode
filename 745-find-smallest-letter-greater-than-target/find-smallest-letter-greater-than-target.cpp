class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int i=0,j=n-1;
        int ans=letters[0];
        while(i<=j){
            int mid=i+(j-i)/2;
            if(letters[mid]>target){
                ans=letters[mid];
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};