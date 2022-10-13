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

bool BigDecimal::operator > (BigDecimal n) const
{
    if(n.num[0] != num[0])
    {
        if(num[0] == '+')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(num[0] == '-')
        {
            if(num.length() > n.num.length())
            {
                return false;
            }
            else if(num.length() < n.num.length())
            {
                return true;
            }
            else if(num.length() == n.num.length())
            {
                bool flag = 1;

                for (int i = 1; i < num.size(); ++i)
                {
                    if (num[i] > n.num[i])
                    {
                        return flag;
                    }
                }
                return flag;
            }
        }
        if(num[0] == '+')
        {
            if(num.length() > n.num.length())
            {
                return true;
            }
            else if(num.length() < n.num.length())
            {
                return false;
            }
            else if(num.length() == n.num.length())
            {
                for (int i = 1; i < num.size(); ++i)
                {
                    if (num[i] > n.num[i])
                    {
                        return true;
                    }
                }

                return false;
            }
        }
    }

}
bool BigDecimal::operator == (BigDecimal n) const
{
    if(!(num>n.num)&&!(num<n.num))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int BigDecimal::Sign(BigDecimal n) const
{
    if(n.num[0]=='-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
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

BigDecimal BigDecimal :: operator + (BigDecimal n) const
{
    string ans="";
    int remainder=0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // If both of them have the same sign
    if(num[0]==n.num[0])
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // If the sign is +
        if(num[0]=='+')
        {
            if(num > n.num)
            {
                for(int i=n.num.length()-1; i>=1; i--)
                {
                    if((num[i+num.length()-n.num.length()]-'0') + (n.num[i]-'0') + remainder > 9)
                    {
                        ans += ((num[i+num.length()-n.num.length()]-'0') + (n.num[i]-'0') + remainder - 10) + '0';
                        remainder=1;
                    }
                    else
                    {
                        ans += ((num[i+num.length()-n.num.length()]-'0') + (n.num[i]-'0') + remainder) + '0';
                        remainder=0;
                    }
                }
                for(int i=num.length()-n.num.length(); i>=1; i--)
                {
                    if((num[i]-'0') + remainder > 9)
                    {
                        ans += ((num[i]-'0') + remainder - 10) + '0';
                        remainder=1;
                    }
                    else
                    {
                        ans += ((num[i]-'0') + remainder) + '0';
                        remainder=0;
                    }
                }
                if(remainder==1)
                {
                    ans += '1';
                }
            }
            else if(num < n.num || num == n.num)
            {
                for(int i=num.length()-1; i>=1; i--)
                {
                    if((num[i]-'0') + (n.num[i+n.num.length()-num.length()]-'0') + remainder > 9)
                    {
                        ans += ((num[i]-'0') + (n.num[i+n.num.length()-num.length()]-'0') + remainder - 10) + '0';
                        remainder=1;
                    }
                    else
                    {
                        ans += ((num[i]-'0') + (n.num[i+n.num.length()-num.length()]-'0') + remainder) + '0';
                        remainder=0;
                    }
                }
                for(int i=n.num.length()-num.length(); i>=1; i--)
                {
                    if((n.num[i]-'0') + remainder > 9)
                    {
                        ans += ((n.num[i]-'0') + remainder - 10) + '0';
                        remainder=1;
                    }
                    else
                    {
                        ans += ((n.num[i]-'0') + remainder) + '0';
                        remainder=0;
                    }
                }
                if(remainder==1)
                {
                    ans += '1';
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // If the sign -
        if(num[0]=='-')
        {
            if(num < n.num)
            {
                for(int i=n.num.length()-1; i>=1; i--)
                {
                    if((num[i+num.length()-n.num.length()]-'0') + (n.num[i]-'0') + remainder > 9)
                    {
                        ans += ((num[i+num.length()-n.num.length()]-'0') + (n.num[i]-'0') + remainder - 10) + '0';
                        remainder=1;
                    }
                    else
                    {
                        ans += ((num[i+num.length()-n.num.length()]-'0') + (n.num[i]-'0') + remainder) + '0';
                        remainder=0;
                    }
                }
                for(int i=num.length()-n.num.length(); i>=1; i--)
                {
                    if((num[i]-'0') + remainder > 9)
                    {
                        ans += ((num[i]-'0') + remainder - 10) + '0';
                        remainder=1;
                    }
                    else
                    {
                        ans += ((num[i]-'0') + remainder) + '0';
                        remainder=0;
                    }
                }
                if(remainder==1)
                {
                    ans += '1';
                }
            }
            else if(num > n.num || num == n.num)
            {
                for(int i=num.length()-1; i>=1; i--)
                {
                    if((num[i]-'0') + (n.num[i+n.num.length()-num.length()]-'0') + remainder > 9)
                    {
                        ans += ((num[i]-'0') + (n.num[i+n.num.length()-num.length()]-'0') + remainder - 10) + '0';
                        remainder=1;
                    }
                    else
                    {
                        ans += ((num[i]-'0') + (n.num[i+n.num.length()-num.length()]-'0') + remainder) + '0';
                        remainder=0;
                    }
                }
                for(int i=n.num.length()-num.length(); i>=1; i--)
                {
                    if((n.num[i]-'0') + remainder > 9)
                    {
                        ans += ((n.num[i]-'0') + remainder - 10) + '0';
                        remainder=1;
                    }
                    else
                    {
                        ans += ((n.num[i]-'0') + remainder) + '0';
                        remainder=0;
                    }
                }
                if(remainder==1)
                {
                    ans += '1';
                }
            }
            ans += '-';
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else
    {
        remainder=0; // yemken yb2a moshkela

        if(num > n.num)
        {
             for(int i=n.num.length()-1; i>=1; i--)
             {
                 if((num[i+num.length()-n.num.length()]-'0') - (n.num[i]-'0') - remainder < 0)
                 {
                     ans += ((num[i+num.length()-n.num.length()]-'0') - (n.num[i]-'0') - remainder + 10) + '0';
                     remainder=1;
                 }
                 else
                 {
                     ans += ((num[i+num.length()-n.num.length()]-'0') - (n.num[i]-'0') - remainder) + '0';
                     remainder=0;
                 }
             }
             for(int i=num.length()-n.num.length(); i>=1; i--)
             {
                 if((num[i]-'0') - remainder < 0)
                 {
                     ans += ((num[i]-'0') - remainder + 10) + '0';
                     remainder=1;
                 }
                 else
                 {
                     ans += ((num[i]-'0') - remainder) + '0';
                     remainder=0;
                 }
             }
             if(num < n.num)
             {
                 ans += '-';
             }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
