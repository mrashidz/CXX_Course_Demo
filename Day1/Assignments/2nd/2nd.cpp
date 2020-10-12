#include <iostream>


char encrypt (char c, unsigned int k) {
    char ret = -1;
            std::cout << "bad char enc:" <<(int) c << std::endl;

    if (c < 65 || c > 90)
        std::cout << "bad char enc:" << c << std::endl;
    else {
        char tmp = c - 65;
        std::cout << "bad char enc:" <<(int)tmp << std::endl;
        if ((k + tmp)>= 26) {
           ret = (k- (26 - tmp))+ 65;
        } else {
            ret = tmp + k + 65;
        }
    }
    return ret;
}

char decrypt (char c, unsigned int k) {
    char ret = -1;
    if (c < 65 || c > 90)
        std::cout << "bad char dec:" << c << std::endl;
    else {
        char tmp = c - 65;
        if (k > tmp) {
            ret = (26 - (k-tmp)) + 65;
        } else {
            ret = (tmp - k) + 65;
        }
    }
    return ret;
}


int main() {
    unsigned int Key = 0;
    std::string cipher,plain;
    std::cout << "Type in the key (0-26):" << std::endl;
    std::cin >> Key;
    Key = Key%27;
    std::cout << "Type in the plain text:" << std::endl;
    std::cin >> cipher;
    std::cout << "Plain Text is: " << cipher << std::endl;
    for (char c: cipher) {
        plain += encrypt(c,Key);
    }
    cipher.clear();

    for (char c:plain) {
        cipher += decrypt(c,Key);
    }





    std::cout << "Key:" << Key << std::endl;
    std::cout << "Plain text :" << cipher << std::endl;
    std::cout << "Cipher text:" << plain << std::endl;




}