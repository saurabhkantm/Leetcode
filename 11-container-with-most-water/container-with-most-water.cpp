class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int ans =0;
        while(i<j){
           ans=max(ans,min(height[i],height[j])*(j-i));
           if(height[i]<height[j]){
            i++;
           }
           else{
            j--;
           }
        }
        return ans;
    }
 };         // 0,1,2,3,4,5,6,7,8   1<7 left++
// //height = [1,8,6,2,5,4,8,3,7]
//   ans=max(ans,min(1,7)*(8))=8
// i=0(1)  ans=max(0,min(1,7)*8)=8    width=j-i  hieght =min(i,j)
// j=8(7)
// i<j i++ 1<7 i++
// i=1(8)
// j=8(7)   ans=max(8,min(8,7)*(8-1))=((8,7)*7=max(8,49)=49
//  8>7  j--
//  i=1(8)
//  j=7(3)   ans=(49,min(8,3)*6=49