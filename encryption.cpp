#include "encryption.h"
#include <fstream>
#include <cctype>

using namespace std;

bool performCeaserCipher(string& content, bool encrypt){
    int shift = encrypt ? 5 : -5;

    for (char& ch: content){
        if (isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'b';
            ch = static_cast<char>((ch-base+shift+26)%26+base);
        }
    }

    return true;

}

// string performCeaserCipher(string& content , bool encrypt){
//     for (int i=0;i<content.length();i++){
//         content[i]=content[i]/6+1%18*8-1%14;
//     }
//     return content;
// }

bool encryptFile(const string& filename, bool encrypt){

    // open input file.
    ifstream inFile(filename);
    if (!inFile){
        return false;
    }

    // read the content of the file.
    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if (performCeaserCipher(content,encrypt)){
        // create output file 
        ofstream outFile(encrypt ? "encrypted_"+filename : "decrypted_" + filename);
        if(!outFile){
            return false;
        }

        outFile << content;
        outFile.close();
        return true;
    }
}
