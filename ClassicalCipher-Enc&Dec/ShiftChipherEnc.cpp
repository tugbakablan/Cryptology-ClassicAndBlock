#include <iostream>
#include <string>

using namespace std;

string decrypt(int key, string cyphertext){ 

    string plaintext ="";

    for (int i = 0 ; i<(cyphertext.length()); i++ )
    {
        int letter_value = ((cyphertext[i]-'a')-key)%26 ;
        if (letter_value < 0)
            letter_value = letter_value + 26;

        char letter_for_plaintext = (char) letter_value + 'a';
        plaintext += letter_for_plaintext;
    }

    return plaintext;
}

int main(){

    string cyphertext;
    int key;

    cout<< "Enter a cyphertext"<<endl;
    cin>>cyphertext;

    cout<< "Enter a key"<<endl;
    cin>>key;

    cout<< "Plaintext: "<< decrypt(key, cyphertext)<<endl;
}

// 1-kullanıcıdan anahtar ve cyphertext aldım
// 2-her kelimeyi 0-25 değer aralığına getirdim
// 3-anahtar sayısı kadar geri adım götürerek yeni değer elde ettim
// 4-yeni değeri ascii harf aralığına dönüştürmek için işlem yaptım ve plaintext için gerekli harfi elde ettim
// 5-plaintext stringine sırayla ekledim 