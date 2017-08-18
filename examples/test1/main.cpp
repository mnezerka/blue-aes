/**
 * Encryption example 
 */

#include <Arduino.h>
#include <blue_aes.h>
#include <blue_pkcs7.h>

#define BLOCK_SIZE 16 // AES 128bit / 8 bits = 16 bytes

// helper method for printing array of bytes
void printArray(String name, unsigned char*arr, int length)
{
    String hx = name + " (hex): ";
    Serial.print(name + ": ");
    for (int i = 0; i < length; i++)
    {
        Serial.write(arr[i]);
        hx += String(arr[i], HEX) + ":";
    }
    Serial.println();
    Serial.println(hx);
}

void testAES128()
{
    char data[1024];
    strcpy(data, "{misamisamisamisami}");

    unsigned char key [] = {'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e'};

    //char cipherb64[16 * 4];
  
    Serial.println("===== TEST AES 128 ====="); 

    printArray("Plain", (unsigned char*)data, strlen(data));
    printArray("Key", key, sizeof(key));

    //unsigned int pkcs7size = paddingPKCS7((unsigned char*)data, strlen(data), BLOCK_SIZE);

    //printArray("Plain", (unsigned char*)data, pkcs7size);
    //Serial.println("PKCS7Size" + String(pkcs7size));

    unsigned int pkcs7_size = blue_aes_pkcs7_encrypt((unsigned char*)data, (unsigned int)strlen(data), key);

    printArray("Encrypted", (unsigned char*)data, pkcs7_size);

    // BASE64 encode ciphered message
    //byte cipherb64len = base64_encode(cipherb64, data, pkcs7size);
    //Serial.println("Encrypted message in B64: " + String(cipherb64)); 
}

void setup(void)
{
    Serial.begin(9600);
}

void loop(void)
{
    testAES128();
    delay(20000);
}

 
