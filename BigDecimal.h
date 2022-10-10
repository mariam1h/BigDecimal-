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
    }

    // If the input is integer
    BigDecimal(int n)
    {
        num=to_string(n);
    }

    friend ostream& operator<<(ostream& os, const BigDecimal& n);

    BigDecimal operator + (BigDecimal n) const;

    bool operator < (BigDecimal n) const;

    bool operator > (BigDecimal n) const;

    bool operator == (BigDecimal n) const;
};


#endif //ASSIGNMENT1_BIGDECIMAL_H
