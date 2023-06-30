class Solution {
public:
    /*
        Brute Force :  
            calculate the power by multiplying the res by x, n times

            double myPow(double x, int n) {
                bool nega = false;
                double res = 1;
                if(n<0){
                    n *= -1;
                    nega = true;
                }
                while(n--)
                    res *= x;
                if(nega) return 1/res;
                return res;
            }

            TC : O(N) -- TLE
            SC : O(1)
    */
    /*
        Binary exponentiation -- recursive
            double binpow(double a,long long b) {
                if (b == 0) return 1;
                double res = binpow(a, b / 2);
                if (b % 2) return res * res * a;
                else return res * res;
            }
            double myPow(double x, int n) {
                bool nega = false;
                double res = 1;
                long long N = (long long)n;
                if(n<0){
                    N *= -1LL;
                    nega = true;
                }
                res = binpow(x,N);
                if(nega) return 1/res;
                return res;
            }

            TC : O(log(N))
            SC : O(log(N))  // stack space

    */
    /*
        Binary exponentiation -- iterative

        TC : O(log(N))
        SC : O(1)
    */
    double myPow(double x, int n) {
        bool nega = false;
        double res = 1;
        long long N = (long long)n;
        if(n<0){
            N *= -1LL;
            nega = true;
        }

        while(N){
            if(N%2 == 1){
                res *= x;
                N -= 1;
            }
            x *= x;
            N /= 2;
        }

        if(nega) return 1/res;
        return res;
    }
};