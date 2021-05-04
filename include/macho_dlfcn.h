
#ifndef __MACHO_DLFCN__
#define __MACHO_DLFCN__

#include <dlfcn.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int macho_dlclose(void * __handle);
extern char * macho_dlerror(void);
extern void * macho_dlopen(const char * __path, int __mode);
extern void * macho_dlsym(void * __handle, const char * __symbol);

#ifdef __cplusplus
}
#endif

#endif // __MACHO_DLFCN__
