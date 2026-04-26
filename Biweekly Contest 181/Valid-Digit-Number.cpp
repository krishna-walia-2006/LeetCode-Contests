class Solution {
public:
    bool validDigit(int n, int x) {
        bool result=false;
        int temp=n,digit=0;
        while(temp!=0) {
            digit=temp%10;
            if(digit==x) result=true;
            temp=temp/10;
        }

        if(digit==x) return false;
        return result;
    }
};
