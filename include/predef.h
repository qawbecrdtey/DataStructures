#ifndef DATASTRUCTURES_PREDEF_H
#define DATASTRUCTURES_PREDEF_H

#include <inttypes.h>

#if __STDC_VERSION__ < 201112L
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE*)NULL)->MEMBER)
#endif

#endif
