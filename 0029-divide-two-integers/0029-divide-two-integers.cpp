class Solution {
public:
    int divide(int dividend, int divisor) {
        // 1. Handle the only overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // 2. Determine the sign of the result using XOR
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // 3. Convert to positive long long to safely calculate without overflowing
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        long long quotient = 0;

        
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;
            
            // Keep multiplying the divisor by 2 until it exceeds the remaining dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the largest found multiple and add to the quotient
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        // 5. Apply the correct sign
        return isNegative ? -quotient : quotient;
    }
};