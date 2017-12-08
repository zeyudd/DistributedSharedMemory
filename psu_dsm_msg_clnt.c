/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "psu_dsm_msg.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

int *
psu_dsm_page_find_1(pageid_t *argp, CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PSU_DSM_PAGE_FIND,
		(xdrproc_t) xdr_pageid_t, (caddr_t) argp,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
psu_dsm_page_creat_1(pageid_t *argp, CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PSU_DSM_PAGE_CREAT,
		(xdrproc_t) xdr_pageid_t, (caddr_t) argp,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
psu_dsm_page_update_1(request_t *argp, CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PSU_DSM_PAGE_UPDATE,
		(xdrproc_t) xdr_request_t, (caddr_t) argp,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

page_t *
psu_dsm_page_request_1(request_t *argp, CLIENT *clnt)
{
	static page_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PSU_DSM_PAGE_REQUEST,
		(xdrproc_t) xdr_request_t, (caddr_t) argp,
		(xdrproc_t) xdr_page_t, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

page_t *
psu_dsm_page_fetch_1(request_t *argp, CLIENT *clnt)
{
	static page_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PSU_DSM_PAGE_FETCH,
		(xdrproc_t) xdr_request_t, (caddr_t) argp,
		(xdrproc_t) xdr_page_t, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

void *
psu_dsm_page_ack_1(pageid_t *argp, CLIENT *clnt)
{
	static char clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PSU_DSM_PAGE_ACK,
		(xdrproc_t) xdr_pageid_t, (caddr_t) argp,
		(xdrproc_t) xdr_void, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return ((void *)&clnt_res);
}