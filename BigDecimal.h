#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#ifndef ASSIGNMENT1_BIGDECIMAL_H
#define ASSIGNMENT1_BIGDECIMAL_H
class BigDecimal
{
private:
    string num;
public:
    // If the input is string
    BigDecimal(string n);

    // If the input is integer
    BigDecimal(int n);

    BigDecimal operator + (BigDecimal n) const;

    BigDecimal operator - (BigDecimal n) const;

    bool operator < (BigDecimal n) const;

    bool operator > (BigDecimal n) const;

    bool operator == (BigDecimal n) const;

    BigDecimal operator = (BigDecimal n);

    int Size(BigDecimal n) const;

    int Sign(BigDecimal n) const;

    friend ostream& operator<<(ostream& os, const BigDecimal& n);
};
#endif //ASSIGNMENT1_BIGDECIMAL_H