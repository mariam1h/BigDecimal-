#include <iostream>
#include <bits/stdc++.h>
#include "BigDecimal.h"

using namespace std;

int main()
{
    BigDecimal num1("+123456789012345678901234567890");
    BigDecimal num2("+113456789011345678901134567890");
    BigDecimal num3("-200000000000000000000000000000");
    BigDecimal num4 = num2 + num1;
    BigDecimal num5 = num2 - num1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 + num1 = " << num4 << endl;
    //Next statement will print 236913578023691357802369135780
    //Next statement will print -313456789011345678901134567890
    cout << "num2 - num1 = " << num5 << endl;
    return 0;
}
