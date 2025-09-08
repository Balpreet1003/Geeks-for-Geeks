class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        // vector<bool>isPrime(n+1,true);
        // for(int i=2;i<=n;i++){
        //     if(isPrime[i]){
        //         for(long long j=1LL*i*i;j<=n;j+=i){
        //             isPrime[j]=false;
        //         }
        //     }
        // }
        // vector<int>ans;
        // for(int i=2;i<=n;i++)
        //     if(isPrime[i] && n%i==0)
        //         ans.push_back(i);
        
        // return ans;
        set<int>ans;
        if(!(n&1))
            ans.insert(2);
        while(!(n&1))
            n>>=1;
            
        for(int i=3;i<=n;i++){
            while(n%i==0){
                ans.insert(i);
                n/=i;
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
