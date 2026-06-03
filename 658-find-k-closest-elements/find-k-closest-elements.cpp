class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int l=0,h=arr.size()-k;
      while(l<h){
        int mid=l+(h-l)/2;
        if(x-arr[mid]>arr[mid+k]-x){
            l=mid+1;
        }
        else{
            h=mid;
        }
      }
        vector<int> ans; 
        for(int i=0;i<k;i++){ 
            ans.push_back(arr[l+i]); 
            }
      return ans;
    }
};