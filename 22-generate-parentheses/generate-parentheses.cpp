class Solution {
public:
   vector<string> ans;
void solve(int i,int j,int n,string str){
          if(i==n&&j==n)ans.push_back(str);
          if(i>n||i<j)return ;

            str+='(';
            solve(i+1,j,n,str);
            int k=str.length()-1;
            str.erase(k,1);
            str+=')';
            solve(i,j+1,n,str);
            return ;
        
    }
    vector<string> generateParenthesis(int n) {
        string str="";
        solve(0,0,n,str);
        return ans;
    }
};