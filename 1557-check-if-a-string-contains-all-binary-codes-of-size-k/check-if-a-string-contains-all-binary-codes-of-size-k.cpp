class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int i=0;
        map<int,int> mp;
        while(i<s.size()){
            if(i>=k-1){
                int n=k-1;
                int binary=0;
                for(int j=i-k+1;j<=i;j++){
                    // cout<<s[j]-48<<endl;
                    binary+=((s[j]-48)*pow(2,n));
                    n--;
                }

                
                 mp[binary]=1;
                 if(mp.size()==pow(2,k))return true;
            }
            i++;
        }
        // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
        // if(mp.size()==pow(2,k))return true;
        return false;
    }
};