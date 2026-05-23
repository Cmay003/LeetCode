class Solution {
public:
    int hcf(int n, int m){
        int a=max(n,m);
        int b=min(n,m);
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    long lcm(long n, long m){
        return ((n*m)/hcf(n,m));
    }
    bool coprime(int n, int m){
        if(hcf(n,m)==1) return true;
        else return false;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;
        for(int num:nums){
            int top=num;
            while(!stack.empty() && !coprime(stack.back(), top)){
                top = lcm(stack.back(), top);
                stack.pop_back();
            }
            stack.push_back(top);
        }
        return stack;
        
    }
};