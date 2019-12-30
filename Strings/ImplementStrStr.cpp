/*Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases.*/


int Solution::strStr(const string A, const string B)
{
    if(A.size() == 0)return -1;
    if(B.size() == 0) return -1;
    if(A.size() < B.size()) return -1;
    
    int idx = 0;
    int k;
    
    
    for(int i = 0; i <= A.size()-B.size();i++)
    {
        int j = i;
        
        if(A[i] == B[0])
        {
            int count = 1;
            int idx = 1;
            for(int k = i + 1; k <= A.size()-B.size();k++)
            {
                if(A[k] == B[idx])
                {
                    idx++;
                    count++;
                }
                if(count == B.size())break;
            }
            if(count == B.size())return j;
        }
        
    }
    return -1;
}
