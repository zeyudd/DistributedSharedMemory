/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PSU_DSM_MSG_H_RPCGEN
#define _PSU_DSM_MSG_H_RPCGEN

#include <rpc/rpc.h>
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PAGESIZE 4096
#define MAXNAME 32

struct page_t {
	u_int size;
	char addr[PAGESIZE];
};
typedef struct page_t page_t;

struct pageid_t {
	char name[MAXNAME];
	u_int size;
};
typedef struct pageid_t pageid_t;

#define PSU_DSM 0x20002222
#define PSU_DSM_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define PSU_DSM_PAGE_FIND 1
extern  int * psu_dsm_page_find_1(pageid_t *, CLIENT *);
extern  int * psu_dsm_page_find_1_svc(pageid_t *, struct svc_req *);
#define PSU_DSM_PAGE_CREAT 2
extern  int * psu_dsm_page_creat_1(pageid_t *, CLIENT *);
extern  int * psu_dsm_page_creat_1_svc(pageid_t *, struct svc_req *);
#define PSU_DSM_PAGE_UPDATE 3
extern  int * psu_dsm_page_update_1(pageid_t *, CLIENT *);
extern  int * psu_dsm_page_update_1_svc(pageid_t *, struct svc_req *);
#define PSU_DSM_PAGE_FETCH 4
extern  page_t * psu_dsm_page_fetch_1(pageid_t *, CLIENT *);
extern  page_t * psu_dsm_page_fetch_1_svc(pageid_t *, struct svc_req *);
extern int psu_dsm_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define PSU_DSM_PAGE_FIND 1
extern  int * psu_dsm_page_find_1();
extern  int * psu_dsm_page_find_1_svc();
#define PSU_DSM_PAGE_CREAT 2
extern  int * psu_dsm_page_creat_1();
extern  int * psu_dsm_page_creat_1_svc();
#define PSU_DSM_PAGE_UPDATE 3
extern  int * psu_dsm_page_update_1();
extern  int * psu_dsm_page_update_1_svc();
#define PSU_DSM_PAGE_FETCH 4
extern  page_t * psu_dsm_page_fetch_1();
extern  page_t * psu_dsm_page_fetch_1_svc();
extern int psu_dsm_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_page_t (XDR *, page_t*);
extern  bool_t xdr_pageid_t (XDR *, pageid_t*);

#else /* K&R C */
extern bool_t xdr_page_t ();
extern bool_t xdr_pageid_t ();

#endif /* K&R C */

/* server info */
#define MAXSERV 100
typedef char server_t[16];
extern int nserver;
extern server_t server[MAXSERV];

enum state{NA, RO, RW};

struct dirent_t{
	pageid_t page;
	int pbits[MAXSERV];
	enum state stat;
	pthread_mutex_t lock;	
};

typedef struct dirent_t dirent_t;

struct dir_t{
	dirent_t dirent;
	struct dir_t *next;
};

typedef struct dir_t dir_t;

extern dir_t *dir;

 
#ifdef __cplusplus
}
#endif

#endif /* !_PSU_DSM_MSG_H_RPCGEN */