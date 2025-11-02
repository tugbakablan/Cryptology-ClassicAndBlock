#include <iostream>
#include <string>

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

string decrypt(int a, int b,int m, string cyphertext){
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
    return plaintext;
}

int main(){

    int a;
    int b;
    int m;
    string cyphertext;

    cout<< "Enter the cyphertext"<<endl;
    cin>>cyphertext;

    cout<<"Enter the key with the order of a then b and then the alphabet lenght you work with "<<endl;
    cin>>a>>b>>m;

    cout<<"Plaintext is: "<< decrypt(a,b,m,cyphertext)<<endl;
}
