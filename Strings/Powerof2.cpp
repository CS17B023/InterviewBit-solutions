/*Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1*/

string divide(string s)
{
    string res = "";
    int rem = 0;
    
    for(int i = 0; i <= s.size() - 1; i++)
    {
        long long num = (s[i] - '0') + 10*rem;
        
        int qnt = num/2;
        rem = num%2;
        res += to_string(qnt);
    }
    
    
    while(res.size() && !(res[0] - '0'))
            res.erase(res.begin());
    return res;
}

bool no_one(string N)
{ 
    
    if(N.size() > 1)
        return 1;
    if(N[0] != '1')
        return 1;
    return 0;
}


int is_Even(string s)
{
    if(( (s[s.size() - 1] - '0') & 1 ) == 0)
        return 1;
    else
        return 0;
}


int Solution::power(string s) 
{
    if(s.size() == 0) return 0;
    if(s.size() == 1)
    {
        if(s[0] == '2' || s[0] == '4' || s[0] == '8') 
            return 1;
        else
            return 0;
    }
    
    while(is_Even(s) && no_one(s) )
    {
         s = divide(s);
         if(s.size() == 1 && s[0] == '1') break;
    }
     
     
     if(no_one(s))
        return 0;
     else
        return 1;
}
