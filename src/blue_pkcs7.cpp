/**
 * PKCS7 padding
 *
 * Copyright (c) 2017 Michal Nezerka
 * All rights reserved.
 * 
 * Developed by: Michal Nezerka
 *               https://github.com/mnezerka/
 *               mailto:michal.nezerka@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal with the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimers.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimers in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of Michal Nezerka, nor the names of its contributors
 *    may be used to endorse or promote products derived from this Software
 *    without specific prior written permission. 
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE SOFTWARE.
 * 
 */

#include <string.h>

unsigned int blue_padding_pkcs7(
    unsigned char *buffer,
    unsigned int content_size,
    unsigned int buffer_size,
    unsigned char block_size)
{
    // compute how many padding bytes are necessary by computing
    // number of bytes missing in last block
    // Note: even if content is aligned with block_size, we need to add
    // one special block (according to PKCS7 standard)
    unsigned char padding_size = block_size - (content_size % block_size);

    //Serial.println(String(content_size) + ':' + String(block_size) + ':' + String(padding_size));

    // check if there is enough space in buffer for all new bytes
    if (content_size + padding_size > buffer_size)
    {
        return 0;
    } 

    // set padding bytes in buffer
    memset(buffer + content_size, padding_size, padding_size);

    // return final size of the content in PKCS7 encoding
    return content_size + padding_size;
}

