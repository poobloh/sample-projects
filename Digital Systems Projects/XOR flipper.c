void printBinary(int x)
{
    int a, b, c;
    a = x;

    for (b = 31; b >= 0; b--)
    {
        c = a >> b;     //Right shift b places in loop, starting with 32nd bit
        if (c & 1)      //Prints what computer sees at that bit (1 or 0)
          printf("1");
        else
          printf("0");
    }
    printf("\n");
}

int main()
{
    int value, y;
    value = 0xff; //11110000 binary

    printf("Before: %d\nIn bin: \n", value);
    printBinary(value);
    value ^= 0xffffffff; //11111111 binary
    printf("\nAfter: %d\nIn bin: \n", value);
    printBinary(value);
    y = 0xf;
    printf("\n%d in bin is:\n", y);
    printBinary(y);
    return 0;
}
