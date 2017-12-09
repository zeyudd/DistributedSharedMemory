/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "msg.h"


void
psu_dsm_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	pageid_t  psu_dsm_page_find_1_arg;
	int  *result_2;
	pageit_T  psu_dsm_page_locate_1_arg;
	int  *result_3;
	pageid_t  psu_dsm_page_creat_1_arg;
	int  *result_4;
	request_t  psu_dsm_page_update_1_arg;
	page_t  *result_5;
	request_t  psu_dsm_page_request_1_arg;
	page_t  *result_6;
	request_t  psu_dsm_page_fetch_1_arg;
	void  *result_7;
	pageid_t  psu_dsm_page_ack_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, PSU_DSM, PSU_DSM_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = psu_dsm_page_find_1(&psu_dsm_page_find_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = psu_dsm_page_locate_1(&psu_dsm_page_locate_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = psu_dsm_page_creat_1(&psu_dsm_page_creat_1_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = psu_dsm_page_update_1(&psu_dsm_page_update_1_arg, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_5 = psu_dsm_page_request_1(&psu_dsm_page_request_1_arg, clnt);
	if (result_5 == (page_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_6 = psu_dsm_page_fetch_1(&psu_dsm_page_fetch_1_arg, clnt);
	if (result_6 == (page_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_7 = psu_dsm_page_ack_1(&psu_dsm_page_ack_1_arg, clnt);
	if (result_7 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	psu_dsm_1 (host);
exit (0);
}
