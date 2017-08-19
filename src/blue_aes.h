/* --COPYRIGHT--,BSD
 * Copyright (c) 2011, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/*
 *  Created on: Nov 3, 2011
 *      Author: Eric Peeters
 *
 *  Extended on: Aug 1, 2017
 *      Author: Michal Nezerka
 */

#ifndef BLUE_AES_H
#define BLUE_AES_H

/**
 * Encryption of data buffer aligned to 128bit blocks
 *
 * @param plain data to be encrypted and result of encrytion (in/out parameter)
 * @param plain_size number of bytes in plain buffer to be encrypted
 * @param aes_key key to be used for encryption (must be 16 bytes)
 */
unsigned int blue_aes_encrypt(
    unsigned char *plain,
    const unsigned int plain_size,
    const unsigned char *aes_key);

/**
 * Encryption of any data buffer, pkcs7 padding is applied before encryption
 *
 * @param plain data to be encrypted and result of encrytion (in/out parameter)
 * @param plain_size number of bytes in plain buffer to be encrypted
 * @param plain_size_max number of bytes available in plain buffer, some bytes
 *        are always needed (at least 1 byte) for pkcs7 padding. Even data
 *        aligned to 128bit blocks are padded
 * @param aes_key key to be used for encryption (must be 16 bytes)
 */
unsigned int blue_aes_pkcs7_encrypt(
    unsigned char *plain,
    const unsigned int plain_size,
    const unsigned int plain_size_max,
    const unsigned char *aes_key);

/**
 * Encryption of single 128bit block 
 *
 * @param state data to be encrypted and result of encrytion (in/out parameter)
 * @param aes_key key to be used for encryption (must be 16 bytes)
 */
void blue_aes_encrypt_block(
    unsigned char *state,
    const unsigned char *aes_key);

#endif /* BLUE_AES_H */
