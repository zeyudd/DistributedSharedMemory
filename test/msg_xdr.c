/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "msg.h"

bool_t
xdr_host_t (XDR *xdrs, host_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->ip, IP_LEN,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_page_t (XDR *xdrs, page_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_u_int (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->addr, PAGE_SIZE,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_pageid_t (XDR *xdrs, pageid_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->name, NAME_LEN,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->size))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_request_t (XDR *xdrs, request_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_pageid_t (xdrs, &objp->pageid))
		 return FALSE;
	 if (!xdr_mode_t (xdrs, &objp->mode))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->from, IP_LEN,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_mode_t (XDR *xdrs, mode_t *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}
