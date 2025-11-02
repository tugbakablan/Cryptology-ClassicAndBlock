#include <iostream>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

int InverseA(int a, int m){
    a = a%m;
    for(int i = 1; i < m; i++ ){
        if((a*i%m == 1)){
            return i;
        }
    }
    return -1;
}

int InverseB(int b, int m){
    int inversed_b = (-b) % m;
    while(inversed_b < 0){
        inversed_b = inversed_b+m;
    }
    return inversed_b;
}

vector<string> bruteForce(int m, string cyphertext){
    vector<string> possibilities;

    for (int a = 1;  a< m; a++){
        if(gcd(a,m) == 1){
            for(int b=0; b<m; b++){
                string plaintext="";
                int inverse_a = InverseA(a,m);
                int inverse_b = InverseB(b,m);
                for(int i = 0; i<(cyphertext.length()); i++){
                    int letter_value = (cyphertext[i]-'a');
                    int letter_value_after_b =  (letter_value + inverse_b)%m;
                    int letter_value_after_b_a = (letter_value_after_b * inverse_a)%m;
                    int last_value = (letter_value_after_b_a + 'a');
                    char letter = (char) last_value;
                    plaintext += letter;
                }
                possibilities.push_back("Key (a,b) = (" + to_string(a) + " " + to_string(b) + ") the text is : " + plaintext);
            }
        }
    }
                return (possibilities);
}

int main(){

    int m;
    string cyphertext;

    cout<< "Enter the cyphertext"<<endl;
    cin>>cyphertext;

    cout<<"Enter the alphabet lenght you work with "<<endl;
    cin>>m;

    vector<string> result = bruteForce(m, cyphertext);
    for (int x= 0; x<(int)result.size() ; x++){
        cout<< result[x] <<endl;
    }
}

                                      