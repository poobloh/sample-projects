uint32_t fromHosttoNetwork(uint32_t hostlong) //little/big to big endian
{
    int a = 1;
    char *b = (char*)&a;    //pointer to mem address
    if(*b+48!='1')          //if == 1 it means little endian (because it points to a lower memory address)
        return hostlong;    //hostlong is already big endian (network/host have same byte order)

    hostlong = ((hostlong << 8) & 0xFF00FF00 ) | ((hostlong >> 8) & 0xFF00FF ); //convert to little endian
    return (hostlong << 16) | (hostlong >> 16);
}

uint32_t fromNetworktoHost(uint32_t netlong) //big endian to little/big
{
    int a = 1;
    char *b = (char*)&a;
    if(*b+48!='1')
        return netlong;     //network and host are both big endian

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