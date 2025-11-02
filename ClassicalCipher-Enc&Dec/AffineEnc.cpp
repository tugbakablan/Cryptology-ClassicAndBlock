#include <iostream>
#include <string>
#include <numeric>

using namespace std;

string encrypt(int a, int b,int m, string plaintext){
    string cyphertext="";
    if(gcd(a,m)== 1){
        for(int i=0; i<(plaintext.length()); i++){
            int letter_value = (plaintext[i]-'a');
            int letter_value_after_a =  letter_value * a;
            int letter_value_after_a_b = (letter_value_after_a + b)%m;
            int last_value = letter_value_after_a_b + 'a';
            char letter = (char) last_value;
            cyphertext += last_value;
        }
        return cyphertext;
    }
    else {
        return "m(alfabedeki harf sayisi) değeri ile asal bir sayi giriniz";
    }
}


int main(){

    int a;
    int b;
    int m;
    string plaintext;

    cout<< "Enter the plaintext"<<endl;
    cin>>plaintext;

    cout<<"Enter the key with the order of a then b and then the alphabet lenght you work with "<<endl;
    cin>>a>>b>>m;

    cout<<"Cyphertext is: "<< encrypt(a,b,m,plaintext);
}
