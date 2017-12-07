const PAGESIZE = 4096;
const NAMELEN = 32;

struct page_t{
	unsigned int size;
	char addr[PAGESIZE];
};

struct pageid_t{
	char name[NAMELEN];
	unsigned int size;
};

program PSU_DSM {
    version PSU_DSM_VERS {
        int PSU_DSM_PAGE_FIND(pageid_t ) = 1;
	int PSU_DSM_PAGE_CREAT(pageid_t) = 2;
	int PSU_DSM_PAGE_UPDATE(pageid_t) = 3;
	page_t PSU_DSM_PAGE_FETCH(pageid_t) = 4; 
    } = 1;
} = 0x20002222;
