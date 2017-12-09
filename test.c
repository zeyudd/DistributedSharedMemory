#include "psu_dsm.h"


int
main (int argc, char *argv[])
{	
	psu_dsm_init();
//	char host[16];
//	strncpy(host, get_local_ip_addr(), 16);

//	char host1[16];
//	strncpy(host1, "130.203.16.29", 16);
	psu_dsm_ptr_t ptr;
/*	if(strncmp(host, host1, 16) == 0){
		printf("machine 1\n");
		ptr = psu_dsm_malloc("hello1", 100);
	}
	else{	
		printf("machine 2\n");	
		ptr = psu_dsm_malloc("world", 100);
	}
*/

	ptr = psu_dsm_malloc("hello", 100);
	
//	char c = *((char *)ptr + 1);
	
	//strncpy(ptr, "PLEASE", 10);
//	*((char *)ptr) = 'H';
	
//	*((char *)ptr + 1) = '\0';
	
//	printf("content = %s", ptr);	:wq
//

	return 0;
	
}

