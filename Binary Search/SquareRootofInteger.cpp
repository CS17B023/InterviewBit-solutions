/*Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY



Input Format

The first and only argument given is the integer A.
Output Format

Return floor(sqrt(A))
Constraints

1 <= A <= 10^9
For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3*/

int Solution::sqrt(int x) 
{
    if(x == 0 || x == 1)
            return x;
        long start = 1;
        long end   = x/2;
        int res;
        while(start <= end)
        {
            long mid = (start + end)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid < x)
            {
                res = mid;
                start = mid + 1;
            }
            else
                end = mid-1;
        }
        return res;
    
}
