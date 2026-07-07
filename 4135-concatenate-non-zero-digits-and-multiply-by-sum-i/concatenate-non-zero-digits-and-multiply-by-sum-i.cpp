class Solution {
public:
    long long sumAndMultiply(int n) {
       string s=to_string(n);
        string a="";
        for(char b:s){
            if(b!='0')
                a.push_back(b);
        }
      if(a=="") return 0;
        long long x=stoll(a);
        long long sum=0;
        for(char b:a) sum+=(b-'0');
        return (x*sum);
    }
};