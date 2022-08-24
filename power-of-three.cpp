class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0)   return false;
        int largestN = pow(3,19);
        cout<<largestN<<endl;
        return (largestN % n) == 0;
    }
};