#include "BigDecimal.h"

ostream& operator<<(ostream& os, const BigDecimal& n)
{
    os<<n.num;
    return os;
}

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
    if(num[0]!=n.num[0])
    {
        if(num[0]=='+')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(num[0]==n.num[0] && num[0]=='+')
    {
        if(num.length() < n.num.length())
        {
            return false;
        }
        else if(num.length() > n.num.length())
        {
            return true;
        }
        else
        {
            for(int i=1; i<num.length(); i++)
            {
                if(num[i]>n.num[i])
                {
                    return true;
                }
                else if(num[i]<n.num[i])
                {
                    return false;
                }
            }
            return false;
        }
    }
    else
    {
        if(num.length() > n.num.length())
        {
            return false;
        }
        else if(num.length() < n.num.length())
        {
            return true;
        }
        else
        {
            for(int i=1; i<num.length(); i++)
            {
                if(num[i]<n.num[i])
                {
                    return true;
                }
                else if(num[i]>n.num[i])
                {
                    return false;
                }
            }
            return false;
        }
    }
}

bool BigDecimal::operator == (BigDecimal n) const
{
    if(!(num>n.num) && !(num<n.num))
    {
        return true;
    }
    return false;
}

BigDecimal BigDecimal::operator + (BigDecimal n) const
{
    string ans="";
    if(num[0]=='+' && n.num[0]=='+')
    {
        int remainder=0;
        for(int i=min(num.length(),n.num.length())-1; i>=0; i--)
        {
            if(((num[i]-'0')+(n.num[i]-'0'))+remainder>9)
            {
                remainder=1;
                ans+=((10-num[i]-'0'-n.num[i]-'0'+remainder)+'0');
            }
            else
            {
                ans+=(((num[i]-'0')+(n.num[i]-'0')+remainder)+'0');
            }
        }

        if(remainder!=0)
        {
            if(num.length()==n.num.length() && remainder!=0)
            {
                ans+='1';
            }
            else
            {
                // First is bigger
                if(num.length()>n.num.length())
                {
                    for(int i=max(num.length(),n.num.length())-min(num.length(),n.num.length()); i>=0; i--)
                    {
                        if(num[i]<'9')
                        {
                            ans+=((num[i]-'0'+1)+'0');
                            break;
                        }
                        else
                        {
                            ans+='0';
                        }
                    }
                }
                // Second is bigger
                else
                {
                    for(int i=max(num.length(),n.num.length())-min(num.length(),n.num.length()); i>=0; i--)
                    {
                        if(n.num[i]<'9')
                        {
                            ans+=((n.num[i]-'0'+remainder)+'0');
                            break;
                        }
                        else
                        {
                            ans+='0';
                        }
                    }
                }
            }
        }
        else
        {
            // First is bigger
            if(num.length()>n.num.length())
            {
                for(int i=max(num.length(),n.num.length())-min(num.length(),n.num.length()); i>=0; i--)
                {
                    ans+=num[i];
                }
            }
            // Second is bigger
            else
            {
                for(int i=max(num.length(),n.num.length())-min(num.length(),n.num.length()); i>=0; i--)
                {
                    ans+=n.num[i];
                }
            }
        }

        reverse(ans.begin(),ans.end());
    }
    cout<<ans<<endl;
}
