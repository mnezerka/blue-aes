
/*
Padding of buffer according to PKCS7 scheme
https://en.wikipedia.org/wiki/Padding_(cryptography)

Be carefull, buffer needs to be large enough since padded content always
occupies more space than original buffer.  (1-block-size)
*/
unsigned int blue_padding_pkcs7(unsigned char *buffer, unsigned int content_size, unsigned char block_size);

