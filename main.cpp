#include "fmIndex.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

    string textFileName = argv[1];
    string pattern = argv[2];

    ifstream textFile("data/" + textFileName);
    string text((istreambuf_iterator<char>(textFile)), istreambuf_iterator<char>());

    FMIndex fmIndex(text);
    cout << fmIndex.count(pattern) << endl;


    return 0;
}