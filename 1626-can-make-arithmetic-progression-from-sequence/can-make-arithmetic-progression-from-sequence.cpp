class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
     sort(arr.begin(), arr.end());
        if(n<=2) return true;
   int  ans=arr[1]-arr[0];
    for(int i=2;i<n;i++){
           if(ans!=arr[i]-arr[i-1]){
            return false;
    }
    }
       return true;
    }
};