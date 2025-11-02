#include <iostream>
#include <string>
#include <vector>

using namespace std;
// burada bir liste olarak döndürmek istedim ve büyük-küçük harf kontrolü yapmadım küçük varsaydığımız için
vector<string> bruteForce(string cyphertext){
    vector<string> possibilities ;
    int key = 0;
    while(key < 26){
        string plaintext ="";
        for(int i = 0; i<(cyphertext.length()); i++){
            int letter_value = (cyphertext[i]-'a') + key;
            if (letter_value > 25)
                letter_value = letter_value%26;
            char letter_for_the_plaintext = (char) letter_value + 'a';
            plaintext += letter_for_the_plaintext;
        }
        possibilities.push_back(plaintext);
        key++;
    }
    return(possibilities);
}

int main(){

    string cyphertext;

    cout<<"Enter a cyphertext" << endl;
    cin>> cyphertext;

    vector<string> result = bruteForce(cyphertext);
    for(int i= 0 ; i< (int)result.size() ; i++){
        cout <<"with the key " <<i<< " plaintext = " << result[i]<<endl;

    }
}