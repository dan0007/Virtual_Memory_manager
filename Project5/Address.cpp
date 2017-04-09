
#include <stdio.h>
#include <limits.h>
#include "address.h"


int main ( int argc, char *argv[] ) {
    laddress_t logical_address;
    page_t     page_num;
    offset_t   offset;
    frame_t    frame_num;
    paddress_t physical_address;

    logical_address = 16916;

    page_num = logical_address >> OFFSET_BITS;
    offset = logical_address & OFFSET_MASK;

    printf("logical address: %d, page number: %d, offset: %d\n", logical_address, page_num, offset);

#ifdef DEBUG
#endif
    printf("logical address: %s\n", itob16(logical_address));

    printf("page number: %s\n", itob8(page_num));

    printf("offset: %s\n", itob8(offset));

    printf("Unit Testing: Now create physical address ...\n");

    frame_num = page_num;
    physical_address = frame_num << OFFSET_BITS | offset;

    printf("frame number:%d, offset: %d, physical address: %d\n", frame_num, offset, physical_address);

    return 0;
}


char *itob(int x)
{
    static char buff[sizeof(int) * CHAR_BIT + 1];
    int i;
    int j = sizeof(int) * CHAR_BIT - 1;

    buff[j] = 0;
    for(i=0;i<sizeof(int) * CHAR_BIT; i++) {
        if(x & (1 << i))
            buff[j] = '1';
        else
            buff[j] = '0';
        j--;
    }
    return buff;
}


char *itob16(int x)
{
    static char buff[17];
    int i;
    int j = 15;

    buff[j] = 0;
    for(i = 0; i < 16; i++) {
        if(x & (1 << i))
            buff[j] = '1';
        else
            buff[j] = '0';
        j--;
    }
    return buff;
}


char *itob8(int x)
{
    static char buff[9];
    int i;
    int j = 7;

    buff[j] = 0;
    for(i=0; i < 8; i++) {
        if(x & (1 << i))
            buff[j] = '1';
        else
            buff[j] = '0';
        j--;
    }
    return buff;
}

