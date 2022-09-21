#include<stdio.h>
#include<stdint.h>
#define ORDER 8
#define MASK(x) (1<<(x))
//GF(2^8)上でmod x^8 + x^4 + x^3 + x + 1で多項式の乗算を行う
int degree(uint64_t polynomial);
void replace(uint64_t polynomial,int order);
int main(void)
{
    uint64_t pol1 = 0x53; //0101 0011
    uint64_t pol2 = 0xca; //1100 1010
    uint64_t temp;
    int deg;
    //uint64_t mod = 0x11b;
    int i;
    //各ビットでシフトしてmodを取るを繰り返す(7 bit目であれば 7 bitシフトするような感じでする．結局次数の足し算)
    for(i=ORDER-1;i>=0;--i)
    {
        if(((pol2&MASK(i))>>i)==1) //多項式の当該次数を見て，1であれば掛け算を行う
        {
            
            pol1 = pol1 <<i;//多項式の当該次数を見て，1であれば掛け算を行う
            //modを取る
            while(1)
            {   
                deg=degree(pol1);     

                if(deg<ORDER) break;
                pol1 = pol1^(0x1b<<(i));
                pol1 = pol1&(0xffffffffffffffff^(1<<(i)) );
                printf("deg %d\n",deg);
                printf("pol1 %lx\n",pol1);
                getchar();
            }
        }

    }
    printf("%02lx\n",pol1);
    return 0;
}
int degree(uint64_t polynomial)
{
  int degree = -1;
  uint64_t ref=1;
  while(1)
    {
      if(ref>polynomial) break;
      ref = (ref << 1);
      //printf("ref : %ld degree : %d\n",ref,degree);
      degree++;
    }
  return degree;
}
