/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include "util.h"
#include "psu_dsm_msg.h"
int nserver;
server_t server[MAXSERV];
dir_t *dir;

// search if page is inside local dir
// return 1 if found, 0 if not found
static int
search_dir(pageid_t page)
{
	dir_t *dirp = dir;
	while(dirp != NULL){
		if(strncmp(dirp->dirent.page.name, page.name, MAXNAME) == 0){
			return 1;
		}
		dirp = dirp->next;
      	}
	return 0;
}

static int
print_dir()
{
	dir_t *dirp = dir;
	printf("dir = \n");
	while(dirp != NULL){
		printf("host %s\n", dirp->dirent.page.name);
		dirp = dirp->next;
      	}
}
// insert a page into local dir
// return 1 if success, 0 if fail
static int
insert_dir(pageid_t page)
{
	printf("insert_dir called.\n");
	dir_t *dirp = dir;
	dir_t **dirpp = &dir;
	while(dirp != NULL){
		dirpp = &((*dirpp)->next);
		dirp = dirp->next;	
      	}

	dir_t *new = malloc(sizeof(dir_t));
	if(new == NULL){
		return 0;
	}
	
	strncpy(new->dirent.page.name, page.name, MAXNAME);
	new->dirent.page.size = page.size;
	int i;
	for(i = 0; i < MAXSERV; i++){
		new->dirent.pbits[i] = 0;
	}
	new->dirent.stat = NA;
	if(pthread_mutex_init(&new->dirent.lock, NULL) != 0){
		perror("mutex init failed.\n");
		return 0;
	}		 

	*dirpp = new;
	new->next = NULL;
	print_dir();
	printf("return = 1\n");
	return 1;
}

// return 1 if found, 0 otherwise.
int *
psu_dsm_page_find_1_svc(pageid_t *argp, struct svc_req *rqstp)
{
	static int  result;
	printf("server called: page_find()\n");
	result = search_dir(*argp);
	printf("return = %d\n", result);
	return &result;
}

// search if a page exits
// create it if not. return 1 for success, 0 for failer.
int *
psu_dsm_page_creat_1_svc(pageid_t *argp, struct svc_req *rqstp)
{
	static int  result;
	int i;
	char local_host[16];
	strncpy(local_host, get_local_ip_addr(), 16);
	
	printf("server %s called: page_creat\n", local_host);
	

		
	//search local dir
	if(search_dir(*argp) == 1){
		result = 1;
		return &result;
	}
	printf("DEBUG1\n");

	// if page already exists on other server dir, return 1 (success).
	for(i = 0; i < nserver; i++){
		if(strncmp(server[i], local_host, 16) != 0){
			CLIENT *clnt;
			int *result_1;
	
			printf("i = %d, %s\n", i, server[i]);
			clnt = clnt_create (server[i], PSU_DSM, PSU_DSM_VERS, "tcp");
			printf("DEBUG3\n");
			if (clnt == NULL) {
				printf("EXIT_1\n");
				clnt_pcreateerror (server[i]);
				exit (1);
			}

			printf("DEBUG4\n");	
			printf("calling page_find on %s\n", server[i]);
			result_1 = psu_dsm_page_find_1(argp, clnt);
			if (result_1 == (int *) NULL) {
				printf("ERRORRRRR\n");
				clnt_perror (clnt, "call failed");
			}

			clnt_destroy (clnt);
			if(*result_1 == 1){
				result = 1;
				printf("returned here!\n");
    				return &result;
			}
		}
	}
	printf("DEBUG2\n");

	// page doesn't exist, create on local server.
	if(insert_dir(*argp) == 1)
		result = 1;
	else 
		result = 0;	
	printf("result = %d\n", result);
	print_dir();
	return &result;
}

// update the dir entry of a page
int *
psu_dsm_page_update_1_svc(pageid_t *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

// request a page from another server
page_t *
psu_dsm_page_fetch_1_svc(pageid_t *argp, struct svc_req *rqstp)
{
	static page_t  result;
	/*
	 * insert server code here
	 */

	return &result;
}
