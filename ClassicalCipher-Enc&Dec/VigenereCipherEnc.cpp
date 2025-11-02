#include <iostream>
#include <string>

using namespace std;

string vigeneCipher(int m, string text, string keytext) {
    string ciphertext = "";

    int j = 0;

    for (int i = 0; i < text.length(); i++) {
        int new_value = text[i] - 'a' + keytext[j] - 'a';
        char new_char = (char)((new_value % m) + 'a');
        ciphertext += new_char;
        j++;

        if (j == (keytext.length() - 1)) {
            j = 0;
        }
    }

    return ciphertext;
}

int main() {
    string plaintext;
    string keytext;
    int m;

    cout << "enter a plaintext" << endl;
    cin >> plaintext;

    cout << "enter the keytext" << endl;
    cin >> keytext;

    cout << "enter the module value" << endl;
    cin >> m;

    cout << "the ciphertext is: " << vigeneCipher(m, plaintext, keytext);
}