#include <stdio.h>
#include <stdint.h>

uint32_t fromHosttoNetwork(uint32_t hostlong) //little/big to big endian
{
    int a = 1;
    char *b = (char*)&a;    //pointer to mem address
    if(*b+48!='1')          //if == 1 it means little endian (because it points to a lower memory address)
        return hostlong;    //hostlong is already big endian (network/host have same byte order)

    /*int i = hostlong;
    i = ((i&0xff000000) >> 24) | ((i&0x00ff0000) >> 8) |
         ((i&0x0000ff00) << 8) | ((i&0x000000ff) <<24); //conversion to little endian
    return i;*/

    hostlong = ((hostlong << 8) & 0xFF00FF00 ) | ((hostlong >> 8) & 0xFF00FF ); //convert to little endian
    return (hostlong << 16) | (hostlong >> 16);
}

uint32_t fromNetworktoHost(uint32_t netlong) //big endian to little/big
{
    int a = 1;
    char *b = (char*)&a;
    if(*b+48!='1')
        return netlong;     //network and host are both big endian

    /*i = ((i&0xff000000) >>> 24) | ((i&0x00ff0000) >> 8) |
            ((i&0x0000ff00) << 8) | ((i&0x000000ff) <<24) //conversion */

    netlong = ((netlong << 8) & 0xFF00FF00 ) | ((netlong >> 8) & 0xFF00FF ); //convert to little endian
    return (netlong << 16) | (netlong >> 16);
}

void printBinary(int x)
{
    int a = x, b, c;

    for (b = 31; b >= 0; b--)
    {
        c = a >> b;                 //Traverses bits in a loop
        if (c & 1)                  //AND logic with 1 to print what computer sees at that bit
            printf("1");            //If & 1 = true print 1
        else
            printf("0");            //If & 1 = false print 0
    }
}

int flipNumberinBinary(int x)
{
    unsigned int num = x;
    unsigned int revNum = x;        //revNum will become reversed a
    int size = 31;                  //nth place - 1, working with 32 bit integers
    for (num >>= 1; num; num >>= 1) //loop shifts revNum 1 bit up, num 1 bit down and addresses values accordingly, up to size - 1
    {
        revNum <<= 1;
        revNum |= num & 1;
        size--;
    }
    revNum <<= size;                //compensate for last bit and put into revNum
    return revNum;
}

int main()
{
    int y = 0xF4C5;
    int mynum = 0x60000000;
    int other = flipNumberinBinary(mynum);
    printf("0x%x ---> 0x%x\n\n", mynum, other);

    printBinary(y);
    printf("\n\n");
    printBinary(flipNumberinBinary(y));
    printf("\n\n\n");

    uint32_t x = 0x5;
    printf("\n%u\n", fromHosttoNetwork(x));
    printf("\n%u\n\n", fromNetworktoHost(x));

    return 0;
}
