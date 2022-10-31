#include "fmIndex.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "tangananica_o_tanganana";
    FMIndex fm(s);
    cout << fm.count("tangana") << endl;
    return 0;
}