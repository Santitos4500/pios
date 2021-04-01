struct table_descriptor_stage1 L1table[512] __attribute--((aligned(4096)));


struct page_descriptor_stage1 L2table[512] __attribute__((aligned(4096)));

void mapPages(void *vaddr, void *paddr){
	unsigned int L2TableIndex = (vaddr >> 21) & 0x1ff;
	unsigned int L1TableIndex = (vaddr >> 30) & 
}
