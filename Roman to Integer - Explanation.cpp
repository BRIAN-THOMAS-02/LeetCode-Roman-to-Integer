Roman to Integer Explanation - "https://leetcode.com/problems/roman-to-integer/"

#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    //creating function 'getInteger' with return type as 'int' to return the corresponding numbers for the Roman characters
    int getInteger(char c)  
    {
        switch(c) //using switch case to return the corresponding numbers
        {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return -1;
        }
    }
    
    int romanToInt(string s)
    {
        int n = s.size() , result = 0 , current , next;
        
        //using while loop looping through all the characters of the input string
        //cout<<"\n";
        int i = 0;
        while(i < n)
        {
            cout<<"\ni : "<<i<<"\tn : "<<n<<"\n";
            
            if(i == n - 1)  //when i = last element of the string...
            {
                result += getInteger(s[i]);  //result will be the last element left
                cout<<"\n\n";
                return result;
            }
            
            cout<<"\n\ngetInteger(s[i]) : "<<getInteger(s[i]);
            cout<<"\ngetInteger(s[i + 1]) : "<<getInteger(s[i + 1]);
            
            current = getInteger(s[i]);  //variable 'current' is for getting the integer of the current value at index
            next = getInteger(s[i + 1]); //variable 'next' is for getting the integer of the next value at index
            
            /*
            Here we are checking if the current int value is greater than next int val :
            a) If it satisfes above condition:
                1) just add the current element into the result
                2) increment index by 1
    
            b) If it doesn't satisfy the above condition: (i.e. the next int value int great than the current int value)        
                1) just add the difference of next val and current val into the result
                2) increment index by 2 (as we are using 2 numbers instead of 1)
            */
            
            if(current >= next)
            {
                cout<<"\n\ncurrent : "<<current;
                cout<<"\nnext : "<<next;
                
                result += current;
                i++;
                
                cout<<"\nresult : "<<result<<"\n\n\n";
            }
                
            else
            {
                cout<<"\n\n\tnext - current : "<<next - current;
                
                result += next - current;
                cout<<"\n\tresult : "<<result;
                i =  i + 2;
                
                cout<<"\n\n\ti += 2 : "<<i<<"\n\n";
            }
        }
        return result;
    }
};

int main()
{
    Solution obj;
    int output = obj.romanToInt("XXIXIMCD");

    cout<<"\nFinal Result : "<<output;
    return 0;
}
