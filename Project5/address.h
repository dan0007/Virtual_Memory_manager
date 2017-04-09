
#ifndef ADDRESS_H
#define ADDRESS_H

/* offset is used to address the location within a page */
#define OFFSET_BITS 8

/* mask is used to extract the offset from a logical address */
#define OFFSET_MASK 0xFF

/* There is no byte data type in C */
typedef unsigned char byte;

/* new data type of pages, frames, and offset */
typedef unsigned int page_t;
typedef unsigned int frame_t;
typedef unsigned int offset_t;
typedef unsigned int laddress_t;
typedef unsigned int paddress_t;


char *itob(int x);
char *itob16(int x);
char *itob8(int x);
#endif
