/*Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer*/

int Solution::reverse(int A) 
{
    
   if(A >= INT_MAX || A <= INT_MIN)return 0;
    int flag = 0;
    if(A < 0 )
    {
         flag = 1;
         A *= -1; 
    }
     
       
        
    int res = 0;
    
    while( A > 0)
    {
        int rem = A%10;
        res = res*10 + rem;
        A = A/10;
    }
    
     if(res - A != 0) return 0;
    
    
    if(flag) res *= -1;
    
   
    return res;
}
