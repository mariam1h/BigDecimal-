#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string modifiy(string s){
    string c="";
    int index=0;
    for(int j=0;j<s.size();j++) {
        if (isalpha(s[index++])) {
            for (int i = index - 1; i < s.size(); ++i) {
                if (s[i] == ' ' && s[i - 1] == ' ') {
                    continue;
                } else c += s[i];
            }
            break;
        }
    }
        transform(c.begin(),c.end(),c.begin(),::tolower);
    c[0]=toupper(c[0]);

    return c;
}

int main() {
   string s;
    getline(cin,s);
    cout<<modifiy(s);

}
