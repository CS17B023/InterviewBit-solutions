/*Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.



Input Format

The only argument given is string A.
Output Format

Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".*/

bool isPal(string A)
{
    int n = A.size();
    int low  = 0;
    int high = n - 1;
 
    while(low <= high)
    {
        if(A[low] != A[high])
            return false;
        else
        {
            low++;
            high--;
        }
    }
    return true;
    
}

int Solution::solve(string A) 
{
    int check = 0;
    int count = 0;
    
    while(A.length() > 0)
    {
        if(isPal(A)) 
        { 
             check = 1; 
             break; 
        } 
        else
        { 
        count++; 
        A.erase(A.begin() + A.length() - 1); 
        } 
    }
    if(check)
    return count;
    
}
