#include<stdio.h>
#include<stdint.h>
//GF(2^128)の1+x+x^2+x^7+x^128を法とするガロア体上での乗算
uint32_t L[4] = {0x1234,0x5678,0x9ABCD,0xEF01}; //128 bitの秘密鍵
int main(void)
{
    uint32_t Y0[4] = {0x0000,0x0000,0x0000,0x0000};
    uint32_t X1[4] = {0xABCD,0x1234,0x5678,0x9ABC};
    
    return 0;
}
