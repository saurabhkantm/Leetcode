class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string t=s;
        sort(t.begin(),t.end());
        int n=t.length();
        int i=0;
        while(i<n && s[i]==t[n-i-1]) i++;
        if(i==n) return num;
        
        char temp=s[i];
        s[i]=t[n-i-1];
        for(int j=n-1;j>=0;j--){
            if(s[j]==s[i]){
                s[j]=temp;
                break;
            }
        }
        num=stoi(s);
        return num;
    }
};