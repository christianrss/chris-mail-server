/* chrismail.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <chrisutils.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int64;

struct s_email {
    char src[64];
    char dst[64];
    char id[64];
    char subject[128];
    char data[];
};
typedef struct s_email Email;

struct s_server {
    char domain[64];
    char server[64];
    int32 ip;
};
typedef struct s_server Server;

#define $1 (int8*)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $16 (int128)
#define $c (char*)
#define $i (int)

bool sendmail(Email*,Server*);
int main(int,char**);