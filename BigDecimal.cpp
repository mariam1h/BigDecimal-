#include "BigDecimal.h"

bool bigger;

// To compare two strings as a number
bool big (string str1, string str2)
{
    if(str1[0] != str2[0])
    {
        if(str1[0] == '+')
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
        if(str1[0] == '-')
        {
            if(str1.length() > str2.length())
            {
                return false;
            }
            else if(str1.length() < str2.length())
            {
                return true;
            }
            else if(str1.length() == str2.length())
            {
                bool flag = 1;

                for (int i = 1; i < str1.size(); ++i)
                {
                    if (str1[i] > str2[i])
                    {
                        return flag;
                    }
                }
                return flag;
            }
        }
        if(str1[0] == '+')
        {
            if(str1.length() > str2.length())
            {
                return true;
            }
            else if(str1.length() < str2.length())
            {
                return false;
            }
            else if(str1.length() == str2.length())
            {
                for (int i = 1; i < str1.size(); ++i)
                {
                    if (str1[i] > str2[i])
                    {
                        return true;
                    }
                }

                return false;
            }
        }
    }
}

BigDecimal::BigDecimal(string n)
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
    if(num=="+0" || num=="-0")
    {
        num="0";
    }
}

BigDecimal::BigDecimal(int n)
{
    num=to_string(n);
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
            bigger = big(num,n.num);
            if(bigger)
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
            else
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
            bigger = big(num, n.num);
            if(!bigger)
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
            else
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
        string spare1=num,spare2=n.num;
        spare1[0]='+';
        spare2[0]='+';
        bigger = big(spare1, spare2);
        if(bigger)
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
            bigger = big(num,n.num);
            if(!bigger)
            {
                ans += '-';
            }
        }
        else
        {
            for(int i=num.length()-1; i>=1; i--)
            {
                if((num[i]-'0') - (n.num[i+n.num.length()-num.length()]-'0') - remainder < 0)
                {
                    ans += ((num[i]-'0') - (n.num[i+n.num.length()-num.length()]-'0') - remainder + 10) + '0';
                    remainder=1;
                }
                else
                {
                    ans += ((num[i]-'0') - (n.num[i+n.num.length()-num.length()]-'0') - remainder) + '0';
                    remainder=0;
                }
            }
            for(int i=n.num.length()-num.length(); i>=1; i--)
            {
                if((n.num[i]-'0') - remainder < 0)
                {
                    ans += ((n.num[i]-'0') - remainder + 10) + '0';
                    remainder=1;
                }
                else
                {
                    ans += ((n.num[i]-'0') - remainder) + '0';
                    remainder=0;
                }
            }
            bigger = big(num,n.num);
            if(bigger)
            {
                ans += '-';
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

BigDecimal BigDecimal :: operator - (BigDecimal n) const
{
    string ans="";
    int remainder=0;

    if(num[0]!=n.num[0])
    {
        string spare1=num,spare2=n.num;
        spare1[0]='+';
        spare2[0]='+';
        bigger = big(spare1,spare2);
        if(bigger)
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
        else
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
        if(num[0]=='-')
        {
            ans += '-';
        }
    }
    else
    {
        remainder=0;
        string spare1=num,spare2=n.num;
        spare1[0]='+';
        spare2[0]='+';
        bigger = big(spare1, spare2);
        if(bigger)
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
        }
        else
        {
            for(int i=num.length()-1; i>=1; i--)
            {
                if((num[i]-'0') - (n.num[i+n.num.length()-num.length()]-'0') - remainder < 0)
                {
                    ans += ((num[i]-'0') - (n.num[i+n.num.length()-num.length()]-'0') - remainder + 10) + '0';
                    remainder=1;
                }
                else
                {
                    ans += ((num[i]-'0') - (n.num[i+n.num.length()-num.length()]-'0') - remainder) + '0';
                    remainder=0;
                }
            }
            for(int i=n.num.length()-num.length(); i>=1; i--)
            {
                if((n.num[i]-'0') - remainder < 0)
                {
                    ans += ((n.num[i]-'0') - remainder + 10) + '0';
                    remainder=1;
                }
                else
                {
                    ans += ((n.num[i]-'0') - remainder) + '0';
                    remainder=0;
                }
            }
            ans += '-';
        }
        if(num[0]=='-')
        {
            if(ans.back()=='-')
            {
                ans.back()='+';
            }
            else
            {
                ans.back()='-';
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    if(!(num > n.num) && !(num < n.num))
    {
        return true;
    }
    else
    {
        return false;
    }
}

BigDecimal BigDecimal:: operator = (BigDecimal n)
{
    return num = n.num;
}

int BigDecimal::Size(BigDecimal n) const
{
    return n.num.size()-1;
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

ostream& operator<<(ostream& os, const BigDecimal& n)
{
    os<<n.num;
    return os;
}

