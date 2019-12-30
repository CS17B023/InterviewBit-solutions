//Given a non-negative number represented as an array of digits,
//add 1 to the number ( increment the number represented by the digits ).
//The digits are stored such that the most significant digit is at the head of the list.

//Example:
//If the vector has [1, 2, 3]
//the returned vector should be [1, 2, 4]
//as 123 + 1 = 124.



vector<int> Solution::plusOne(vector<int> &A) 
{
    if(A.size() == 1 && A[0] < 9)
    {
        A[0]++;
        return A;
    }
    
    vector<int> res;
    int n = A.size();
    int carry = 1;
    int sum = 0;
    
    
    int counter = 0;
    int j = 0;
    while(A[j] == 0)
    {
        counter++;
        j++;
    }
    
    
    
    
    for(int i = n-1; i >= 0; i--)
    {
        sum = A[i] + carry;
        if(sum > 9)
        {
            carry = sum/10;
            res.push_back(sum%10);
            // A[i] = sum%10;
        }
        else
        {
            carry = 0;
            res.push_back(sum);
            // A[i] = sum;
        }
    }
    
    
    
    if(counter == 0 && carry == 1)
        res.push_back(1); 
    else
    {
        for(int i = 0; i < counter ;i++)
            res.pop_back(); 
    }

    reverse(res.begin(),res.end());
    
    return res;
}
    

