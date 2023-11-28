class Solution {
public:
    string convertToTitle(int columnNumber) {
    int n=    columnNumber;
        return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char) ((n - 1) % 26 + 'A');
    }
};