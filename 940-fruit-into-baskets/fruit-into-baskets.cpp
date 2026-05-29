class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0,len=0;
        int n=fruits.size();
        map<int,int>m;
        while(j<n){
            m[fruits[j]]++;
            while(m.size()>2){
                m[fruits[i]]--;
                if(m[fruits[i]]==0){
                    m.erase(fruits[i]);
                }
                i++;
            }
                len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};