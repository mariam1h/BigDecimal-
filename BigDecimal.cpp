#include "BigDecimal.h"

bool BigDecimal::operator < (BigDecimal n) const
{
    if(num[0]!=n.num[0])
    {
        if(num[0]=='+')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if(num[0]==n.num[0] && num[0]=='+')
    {
        if(num.length() < n.num.length())
        {
            return true;
        }
        else if(num.length() > n.num.length())
        {
            return false;
        }
        else
        {
            for(int i=1; i<num.length(); i++)
            {
                if(num[i]>n.num[i])
                {
                    return false;
                }
                else if(num[i]<n.num[i])
                {
                    return true;
                }
            }
            return false;
        }
    }
    else
    {
        if(num.length() > n.num.length())
        {
            return true;
        }
        else if(num.length() < n.num.length())
        {
            return false;
        }
        else
        {
            for(int i=1; i<num.length(); i++)
            {
                if(num[i]<n.num[i])
                {
                    return false;
                }
                else if(num[i]>n.num[i])
                {
                    return true;
                }
            }
            return false;
        }
    }
}

ostream& operator<<(ostream& os, const BigDecimal& n)
{
    os<<n.num;
    return os;
}
