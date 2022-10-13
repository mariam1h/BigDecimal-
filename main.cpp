#include <iostream>
#include <bits/stdc++.h>
#include "BigDecimal.h"

using namespace std;

int main()
{
    BigDecimal num1("+888");
    BigDecimal num2("-88");
    if(num1<num2) cout<<1;
    cout<<num1+num2;
    return 0;
}
