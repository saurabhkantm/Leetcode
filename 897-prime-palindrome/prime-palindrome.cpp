class Solution {
public:
    bool isprime(int n)
    {
        if(n==0 || n==1) return false;
        for(int i =2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
    int primePalindrome(int n) 
    {
        // std::ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        if(n>=8 && n<=11) return 11;
        for(int i =1;i<=100000;i++)
        {
            string s = to_string(i); //convert int to string
            string r =s; 
            reverse(r.begin(),r.end()); //reverse the string and store in r
            int y = stoi(s+r.substr(1)); //  adding r in s except first character and convering to integer
            if(y>=n && isprime(y)) return y; // checking if it is prime or not.
        }
        return 0;
    }
};