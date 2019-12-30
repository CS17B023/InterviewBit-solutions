/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB */

string Solution::convertToTitle(int n) 
{
    
    string res = "";
    while (n > 0) 
    { 
        
        int rem = n%26; 
  
        if (rem==0) 
        { 
            res += 'Z'; 
            n = (n/26)-1; 
        } 
        else 
        { 
            res += ((rem-1) + 'A'); 
            n = n/26; 
        } 
    } 
    reversee(res.begin(),res.end());
    return res;
}
