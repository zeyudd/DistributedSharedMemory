/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "psu_dsm_msg.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "util.h"

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif


static void
psu_dsm_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		pageid_t psu_dsm_page_find_1_arg;
		pageid_t psu_dsm_page_creat_1_arg;
		pageid_t psu_dsm_page_update_1_arg;
		pageid_t psu_dsm_page_fetch_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case PSU_DSM_PAGE_FIND:
		_xdr_argument = (xdrproc_t) xdr_pageid_t;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) psu_dsm_page_find_1_svc;
		break;

	case PSU_DSM_PAGE_CREAT:
		_xdr_argument = (xdrproc_t) xdr_pageid_t;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) psu_dsm_page_creat_1_svc;
		break;

	case PSU_DSM_PAGE_UPDATE:
		_xdr_argument = (xdrproc_t) xdr_pageid_t;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) psu_dsm_page_update_1_svc;
		break;

	case PSU_DSM_PAGE_FETCH:
		_xdr_argument = (xdrproc_t) xdr_pageid_t;
		_xdr_result = (xdrproc_t) xdr_page_t;
		local = (char *(*)(char *, struct svc_req *)) psu_dsm_page_fetch_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	nserver = 2;
	strncpy(server[0], "130.203.16.28", 16);
	strncpy(server[1], "130.203.16.29", 16);
	dir = NULL;
	printf("server is up\n");
	printf("%s\n", get_local_ip_addr());
	register SVCXPRT *transp;

	pmap_unset (PSU_DSM, PSU_DSM_VERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, PSU_DSM, PSU_DSM_VERS, psu_dsm_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (PSU_DSM, PSU_DSM_VERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, PSU_DSM, PSU_DSM_VERS, psu_dsm_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (PSU_DSM, PSU_DSM_VERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
