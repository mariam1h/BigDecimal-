#include <iostream>
#include <bits/stdc++.h>
#include "BigDecimal.h"

using namespace std;

int main()
{
    BigDecimal num1("-99");
    BigDecimal num2("87");
    BigDecimal num3("0");
    if(num2==num1)
    {
        cout<<"YES";
    }
    return 0;
}
