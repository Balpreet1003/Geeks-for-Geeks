// User function Template for C++

class Solution {
    int get_xor(int x){
        int y=x%4;
        if(y==1){
            return 1;
        }
        if(y==2){
            return x+1;
        }
        if(y==3){
            return 0;
        }
        return x;
    }
  public:
    int findXOR(int l, int r) {
        int x=get_xor(l-1);
        int y=get_xor(r);
        return y^x;
    }
};