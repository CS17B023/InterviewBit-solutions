/*Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.



Input Format

The only argument given is string A.
Output Format

Return the string A after reversing the string word by word.
For Example

Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"*/


string Solution::solve(string A) 
{
    string res = "";
    int i;
    int n = A.size();
    
    if(A.size() == 0)return A;
    if(A.size() == 1)
    {
        if(A[0] == ' ')return res;
        else
        return A;
    }
    
    for(i = n - 1; i >= 0; i--)
        {
            if(A[i] != ' ')
                break;
        }
    int aage = 0;
    for(aage = 0; aage < n; aage++)
    {
        if(A[i] != ' ')
                break;
    }
    string kuku = "";
    while(A[aage] != ' ' && aage < A.size())
    {
        kuku += A[aage];
        aage++;
    }
    
    if(aage != A.size())
    {
        
    
        for(int j = i; j >= aage;)
        {
            string temp = "";
            int k = j;
            while(A[k] != ' ' && k >= aage)
            {
                temp += A[k];
                k--;
            }
            while(A[k] == ' ' && k >= aage)
                k--;
                
            reverse(temp.begin(),temp.end());
            res += temp;
            res += " ";
            
            j = k;
        }
    }
    //reverse(kuku.begin(),kuku.end());
    res += kuku;
    
    
    return res;
}
