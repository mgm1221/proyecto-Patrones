
#include <bits/stdc++.h>

using namespace std;

struct suffix
{
    int indice;
    //string data;
    char* data;
};

class suffixcompare{
    public: 
        /*bool operator()(suffix a, suffix b){
            if(a.data< b.data) return true;
            return false;
        }*/
        bool operator()(suffix a, suffix b){
            if(strcmp(a.data,b.data)<0) return true;
            return false;
        }
};


class SuffixArray{
    private:

        int* SA;
        //string txt;
        char* txt;
        int textlength;
    public:

        SuffixArray(string text){
            txt = new char[text.length()];
            textlength = text.length();
            strcpy(txt,text.c_str());
            
            //txt = text;


            //vector<suffix> StringSuffixArray;
            //StringSuffixArray.reserve(txt.length());

            struct suffix total[textlength];
            //suffix x;
            for (int i = 0; i < text.length(); i++){
                
                total[i].data = /*txt.substr(i)*/ (txt+i);
                total[i].indice = i;
                /*x.data = txt.substr(i);
                x.indice = i;
                StringSuffixArray.push_back(x);*/

            }
            
            suffixcompare comparator;
            sort(total,total +(text.length()),comparator);
            //sort(StringSuffixArray.begin(),StringSuffixArray.end(),comparator)

            SA = new int[text.size()];

            for (int i = 0; i < text.length(); i++)
            {
                //SA[i] = StringSuffixArray[i].data;
                SA[i] = total[i].indice;

            }
            
        }

        int countSA(string pattern){

            int middle, right = textlength, left = 0, rep = 0, pos, comparacion, tamPatron = pattern.length();
            bool found = false;
            char pat[tamPatron];
            strcpy(pat,pattern.c_str());
            //busqueda de primera repeticion 
            while (right>= left && !found)
            {
                middle = (right+ left)/2;
                pos = SA[middle];
                comparacion = strncmp(pat,txt+pos,tamPatron);

                if(comparacion == 0){
                    rep++;
                    found = true;
                }else if(comparacion < 0){
                    right = middle -1;
                }else{
                    left = middle +1;
                }

                /*string actual = txt.substr(pos, pattern.length());
                
                if(pattern == actual){
                    rep++;
                    found = true;
                }else if(pattern < actual){
                    right = middle -1;
                }else{
                    left = middle +1;
                }*/
                
            }
            int rightSearch = middle+1;

            while (rightSearch<textlength)
            {
                pos = SA[rightSearch];
                /*string actual = txt.substr(pos, pattern.length());
                
                if(pattern == actual){
                    rep++;
                }else{
                    break;
                }*/
                comparacion = strncmp(pat,txt+pos,tamPatron);

                if(comparacion == 0){
                    rep++;
                }else{
                    break;
                }
                rightSearch++;

            }

            int leftSearch = middle -1;

            while(leftSearch>=0){
                pos = SA[leftSearch];
                comparacion = strncmp(pat,txt+pos,tamPatron);

                if(comparacion == 0){
                    rep++;
                }else{
                    break;
                }
                /*string actual = txt.substr(pos, pattern.length());
                
                if(pattern == actual){
                    rep++;
                }else{
                    break;
                }*/
                leftSearch--;
            }
            return rep;
        }

};
