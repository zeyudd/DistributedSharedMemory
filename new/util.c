#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "psu_dsm_msg.h"

unsigned long
hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void get_local_ipaddr(char ip[IP_LEN])
{
	int fd;	
	struct ifreq ifr;
     
	char iface[] = "eth0";
     
   	fd = socket(AF_INET, SOCK_DGRAM, 0);
   
   	ifr.ifr_addr.sa_family = AF_INET;
         
   	strncpy(ifr.ifr_name , iface , IFNAMSIZ-1);
                  
	ioctl(fd, SIOCGIFADDR, &ifr);
                       
    	close(fd);
    
     	strncpy(ip, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr), IP_LEN);
 }

