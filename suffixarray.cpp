
#include <bits/stdc++.h>

using namespace std;

struct suffix
{
    int indice;
    string data;
};

class suffixcompare{
    public: 
        bool operator()(suffix a, suffix b){
            if(a.data< b.data) return true;
            return false;
        }
};


class SuffixArray{
    private:

        int* SA;
        string txt;

    public:

        SuffixArray(string text){
            txt = text;

            vector<suffix> StringSuffixArray;

            for (int i = 0; i < text.length(); i++){
                
                suffix x;
                x.data = text.substr(i,text.length());
                x.indice = i;
                StringSuffixArray.push_back(x);

            }
            
            suffixcompare comparator;
            sort(StringSuffixArray.begin(),StringSuffixArray.end(),comparator);

            SA = new int[txt.size()];
            int i = 0;

            for (int i = 0; i < StringSuffixArray.size(); i++)
            {
                SA[i] = StringSuffixArray[i].indice;
            }
        }

        int countSA(string pattern){

            int middle, right = txt.length(), left = 0, rep = 0, pos;
            bool found = false;
            //busqueda de primera repeticion 
            while (right>= left && !found)
            {
                middle = (right+ left)/2;
                pos = SA[middle];
                string actual = txt.substr(pos, pattern.length());
                
                if(pattern == actual){
                    rep++;
                    found = true;
                }else if(pattern < actual){
                    right = middle -1;
                }else{
                    left = middle +1;
                }
                middle = (right+ left)/2;
            }
            int rightSearch = middle+1;

            while (rightSearch<txt.length())
            {
                pos = SA[rightSearch];
                string actual = txt.substr(pos, pattern.length());
                
                if(pattern == actual){
                    rep++;
                }else{
                    break;
                }
                rightSearch++;
            }

            int leftSearch = middle -1;
            while(leftSearch>=0){
                pos = SA[leftSearch];
                string actual = txt.substr(pos, pattern.length());
                
                if(pattern == actual){
                    rep++;
                }else{
                    break;
                }
                leftSearch--;
            }
            return rep;
        }

};
