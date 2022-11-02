#include "fmIndex.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

    string textFileName = argv[1];
    string pattern = argv[2];

    ifstream textFile("data/" + textFileName);
    string text;
    string str;

    int count = 0;
    while(getline(textFile, str) && count <= 200) {
        text += str;
        count++;
    };

    FMIndex fmIndex(text);
    cout << fmIndex.count(pattern) << endl;


    return 0;
}