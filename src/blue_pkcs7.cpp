#include <string.h>

unsigned int blue_padding_pkcs7(unsigned char *buffer, unsigned int content_size, unsigned char block_size)
{
    // compute how many padding bytes are necessary
    // get number of bytes missing in last block
    // even if content is aligned with block_size, we need to add
    // one special block (according to PKCS7 standard)
    unsigned char padding_size = block_size - (content_size % block_size);

    //Serial.println(String(content_size) + ':' + String(block_size) + ':' + String(padding_size));

    // set those bytes in buffer
    memset(buffer + content_size, padding_size, padding_size);

    // return final size of the content in PKCS7 encoding
    return content_size + padding_size;
}

