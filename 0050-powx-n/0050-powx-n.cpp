class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; 
        
        // Make N positive, but do NOT flip x yet
        if (N < 0) {
            N = -N;
        }
        
        // Calculate the power normally
        double ans = fastPow(x, N);
        
        // If the original power was negative, do the division just once at the end
        if (n < 0) {
            return 1.0 / ans;
        }
        
        return ans;
    }
    
private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        
        double half = fastPow(x, n / 2);
        
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};