/*Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.*/


int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    
    long long int rem = 1;
    int check = 0;
    
    if(x == 0)
        return 0;
    if(n == 0)
    {
        if(d == 1) 
            return 0;
        else
            return 1;
    }
    if(x < 0)
    {
        x = abs(x);
        if(n%2 != 0)
            check = 1;
    }
    
    long long int temp = x%d;
    
    while(n != 0)
    {
        if(n%2 != 0)
            rem = (rem*temp)%d;

        temp = temp*temp;
        temp = temp%d;
        
        n = n/2;
        if(rem > d)
            rem = rem%d;
        
    }
    
    if(check)
        return d-rem;
    
    return rem;
}
    
    
    

