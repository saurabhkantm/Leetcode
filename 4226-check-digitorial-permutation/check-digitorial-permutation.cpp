class Solution {
public:
    long long factSum(int n){
        long long sum = 0;
        while(n){
            int d = n%10;
            n /= 10;
            
            long long fact = 1;
            while(d){
                fact *= d;
                d--;
            }

            sum += fact;
        }

        return sum;
    }
    
    bool isDigitorialPermutation(int n) {
        vector<int> arr(10, 0);

        long long sum = factSum(n);
        // cout<<sum<<endl;
        while(n){
            int d = n%10;
            n /= 10;
            arr[d]++;
        }

        while(sum){
            int d = sum % 10;
            sum/=10;
            arr[d]--;
        }

        for(int i=0;i<10;i++){
            if(arr[i] != 0)
                return 0;
        }

        return 1;
    }
};