#ifndef _PSU_DSM_H_
#define _PSU_DSM_H

typedef void* psu_dsm_ptr_t;

psu_dsm_ptr_t psu_dsm_malloc(char* name, size_t size);

void psu_dsm_free(char* name);

#endif
