#include <bits/stdc++.h>
#include "suffixarray.cpp"

using namespace std;

int main(){
    string s;
    getline(cin,s);
    SuffixArray suffixarray = SuffixArray(s);
    cout<< 1<< endl;
    cout<< suffixarray.countSA("rhoncus")<< endl;
    return 0;
}