#include "list.h"
#include "page.h"
#define NPAGES 128
#define NULL (void*)0
extern int __end;

struct ppage physical_page_array[NPAGES]; 
struct ppage* free_list = NULL;

void init_pfa_list(void) {
        void* physical_address = (((unsigned long)&__end) & ~(0x200000 - 1)) + 0x200000;
        for (int z = 0; z < NPAGES; z++){
		listAdd(&free_list, &physical_page_array[z]);
		physical_page_array[z].physical_addr = physical_address;
                physical_address += 0x200000;
	}
}

struct ppage *allocate_physical_pages(unsigned int npages) {
        struct ppage* new_var = free_list;
        struct ppage* new_list = NULL;
        for (int z = 0; z < npages; z++){
                listRemove(new_var);
                listAdd(&new_list, new_var);
        }
        return new_list;
}

void free_physical_pages(struct ppage *ppage_list){
        struct ppage* new_var = ppage_list;
        while (ppage_list != NULL){
                listRemove(new_var);
                listAdd(&free_list, new_var);
	}
}
