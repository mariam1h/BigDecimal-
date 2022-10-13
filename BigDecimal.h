#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#ifndef ASSIGNMENT1_BIGDECIMAL_H
#define ASSIGNMENT1_BIGDECIMAL_H
class BigDecimal
{
private:
    string num="0";
public:
    // If the input is string
    BigDecimal(string n)
    {
        bool check=true;
        // First Digit
        if(n[0]!='-' && n[0]!='+' && !isdigit(n[0]))
        {
            check=false;
        }
        // All Digits
        for(int i=1; i<n.length(); i++)
        {
            if(!isdigit(n[i]))
            {
                check=false;
            }
        }
        if(check)
        {
            if(isdigit(n[0]))
            {
                n.insert(0,"+");
            }
            num=n;
        }
        else
        {
            cout<<"Invalid input"<<endl;
        }
        for(int i=1; i<n.length(); i++)
        {
            if(num[i]=='0')
            {
                num.erase(i,i);
            }
            else
            {
                break;
            }
        }
    }
    // If the input is integer
    BigDecimal(int n)
    {
        num=to_string(n);
    }

    BigDecimal operator + (BigDecimal n) const;

    BigDecimal operator - (BigDecimal n) const;

    bool operator < (BigDecimal n) const;

    bool operator > (BigDecimal n) const;

    bool operator == (BigDecimal n) const;

    BigDecimal operator = (BigDecimal n) const;

    int Sign(BigDecimal n) const;

    int Size(BigDecimal n) const;

    friend ostream& operator<<(ostream& os, const BigDecimal& n);
};
#endif //ASSIGNMENT1_BIGDECIMAL_H