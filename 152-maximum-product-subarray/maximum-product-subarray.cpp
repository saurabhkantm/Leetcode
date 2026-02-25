class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int prod=1;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            maxi=max(maxi,prod);
            if(prod==0)
            prod=1;
        }
         prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            maxi=max(maxi,prod);
            if(prod==0)
            prod=1;
        }
return maxi;

    }
};

//  //nums = [2,3,-2,4]
//  //left to right 
//  [2]=2
//  [2,3]=6                              [2,3,0,4,5]
//  [2,3,-2]=-12
//  [2,3,-2,4]=-48
//  //right to left
//  [4]=4      //output:6
//  [4,-2]=-8
//  [4,-2,3]=-24
//  [4,-2,3,2]=-48

//  nums = [-2,0,-1]
//  //l to r
//  [-2]=-2
//  [-2,0]=0
//  [-2,0,-1]=0
//  //r to l    output :0
//  [-1]=-1
//  [-1,0]=0
//  [-1,0,-2]=0