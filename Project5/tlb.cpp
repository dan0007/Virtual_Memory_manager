
#include "tlb.h"
#include <iostream>
#include <bitset>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdio.h>


#define OFFSET_BITS 8
#define OFFSET_MASK 0xFF
#define NUM_PAGES   256
#define NUM_FRAMES  256
#define PAGE_SIZE   256
#define TLB_SIZE    16
#define TRUE        1
#define FALSE       0

using namespace std;

physical_memory_t physical_memory;

int main () {
    tlb_t my_tlb;
    page_t     page_num;
    frame_t    frame_num;

    page_num = 10;
    frame_num = 3;

    TLB_init(&my_tlb);
    TLB_display(my_tlb);
    tlb_replacement_FIFO(page_num, frame_num, &my_tlb);

    return 0;
}

int TLB_init(tlb_t *tlb) {
    unsigned int i;

    for (i = 0; i < TLB_SIZE; i++)
        tlb->tlb_entry[i].valid = FALSE;

    return 0; /* success */
}

int TLB_replacement_FIFO(page_t page_num, frame_t frame_num, tlb_t* tlb){
    tlb_entry_init(&tlb->table[tlb->first_in], address.page_number, frame_number);
	tlb->first_in = ((tlb->first_in + 1) % TLB_ENTRIES);
	return 0;

}

int TLB_display(tlb_t tlb) {
    unsigned int i;

    for (i = 0; i < TLB_SIZE; i++) {
        printf("TLB entry %d, page num: %d, frame num: %d, ", i, tlb.tlb_entry[i].page_num, tlb.tlb_entry[i].frame_num);
        if (tlb.tlb_entry[i].valid == FALSE)
            printf("Invalid\n");
        else printf("Valide\n");
    }

    return 0;
}

int logic_address_loader(string logic_address_file_name, vector<logic_address_t> *logic_address_list){
    ifstream instream;
    int count = 0;
    instream.open(logic_address_file_name);
    if(instream.fail()){
        cout << "File failed to open.";
        exit(1);
    }
    unsigned int temp;
    while (!instream.eof()) {
        instream >> temp;
        logic_address_list->push_back(temp);
        count++;
    }
    instream.close();
    return count;
}

int extract_logic_address(logic_address_t logic_address, page_t *page_num, offset_t *offset){
    // accepts 32 bit. but only considers right 16 bits.

    string s = bitset< 32 >(logic_address).to_string(); // string conversion

    string numStr = s.substr(16, 24);
    string offsetStr = s.substr(24, 32);

    int numVal = int(bitset< 8 >(numStr).to_ulong());

    int offsetVal = int(bitset< 8 >(offsetStr).to_ulong());

    *page_num = numVal;
    *offset = offsetVal;

    return 0;
}

int TLB_hit_miss(){
    return 0;
}

int search_TLB(page_t p_num, tlb_t tlb, bool *is_tlb_hit, frame_t *f_num){
    return 0;
}

int search_page_table(page_t p_num, page_table_t p_table, bool *is_page_fault, frame_t *f_num){
    return 0;
}

int is_TLB_hit(){
    return 0;
}

int page_fault_handler(page_t p_num, frame_t frame_num, physical_memory_t *physical_mem, page_table_t *p_table, tlb_t *tlb){
    return 0;
}

int create_physical_address(frame_t frame_num, offset_t offset, physical_address_t *physical_address){
    return 0;
}

int read_physical_memory (physical_address_t p_addr, physical_memory_t physical_mem, value_t *value){
    return 0;
}

int update_address_value_list(logic_address_t l_addr, physical_address_t p_addr, value_t value, address_value_list_t addr_value_list) {
    return 0;
}

int output_address_value_list(const char *output_file_name, address_value_list_t addr_value_list){
    return 0;
}

int load_frame_to_physical_memory(page_t page_num, const char *backing_store_file_name, physical_memory_t physical_memory, frame_t *frame_num){
    FILE *file = fopen(backing_store_file_name, "r" );
    fpos_t pos;
    char one_byte;

    if (file == 0 ) {
        printf( "Could not open file: %s.\n", backing_store_file_name);
    }

    else {
        fseek(file, page_num, SEEK_SET);
        fgetpos(file, &pos);
        unsigned int frame;
        for (frame = 0; frame < 256; frame++) {
            if(physical_memory[frame] != NULL){
                break;
            }
        }

        for (int i = 0; i < 256; i++) {
            fread(&one_byte, 1, 1, file);
            physical_memory[frame][i] = one_byte;
        }

        fclose( file );
        frame_num = &frame;
    }
    return 0;
}

int init_page_table(page_table_t page_table){
    for (int i = 0; i < 256; i++) {
        page_table[i] = NULL;
    }
    return 0;
}

int TLB_replacement_LRU(page_t p_num, frame_t f_num, tlb_t *tlb){

      int oldest_tlb = 0;
	int i;
	for (i = 0; i < entry.size; i++) {
		if(tlb->entry[i] == NULL) {
			longest_tlb = i;
			break;
		}else if (oldest_time < tlb->entry[i]->last_used) {
			oldest_tlb = i;
			oldest_time = tlb->entry[i]->last_used;
		}
	}
	tlb_entry_init(&tlb->entry[i].valid, address.page_number, frame_number);

}
