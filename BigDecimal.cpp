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
bool BigDecimal::operator > (BigDecimal n) const {
    if (n.num[0] != num[0]) {
        if (num[0] == '+')return true;
        else {
            return false;
        }
    } else {
        if (num[0] == '-') {
            if (num.length() > n.num.length())
                return false;
            else if (num.length() < n.num.length()) {
                return true;
            } else if (num.length() == n.num.length()) {
                bool flag = 1;
                for (int i = 1; i < num.size(); ++i) {
                    if (num[i] > n.num[i])return flag;
                }
                return flag;
            }
            if (num[0] == '+') {
                if (num.length() > n.num.length())
                    return true;
                else if (num.length() < n.num.length()) {
                    return false;
                } else if (num.length() == n.num.length()) {
                    bool flag = 0;
                    for (int i = 1; i < num.size(); ++i) {
                        if (num[i] > n.num[i])return flag;
                    }
                    return flag;
                }
            }
        }
    }

}
bool BigDecimal::operator == (BigDecimal n) const {
    if(!(num>n.num)&&!(num<n.num))
        return true;
    else {
        return false;
    }
}
int BigDecimal::Sign(BigDecimal n) const
{
    if(n.num[0]=='-')return 0;
    else return 1;
}
int BigDecimal::Size(BigDecimal n) const
{
    return n.num.size()-1;
}

ostream& operator<<(ostream& os, const BigDecimal& n)
{
    os<<n.num;
    return os;
}
