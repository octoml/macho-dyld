## Mach-O Image Loader. Tolerant to unsigned modules.

### Purpose of this module
This is a simplified version of dynamic linker inherited from original Apple sources. 
The key difference is in a switched off signature check for loaded binaries. iOS platform 
doesn't provide mechanic to load unsigned binary, but you may need it for some developer 
purposes like benchmarking/testing code  with real device. Using of this linker version 
let you get around this limitation.

This library exposes next symbols:
 - macho_dlopen
 - macho_dlclose
 - macho_dlsym
 - macho_dlerror

Use it instead of original Posix version.

### Known limitations
- Load only by absolute path
- There is no recurrent dependencies loading (all required modules should be
  preloaded in process before)
- Works only on system with enabled JIT permissions. Ex: iOS under debugger.
- Only RTLD_LAZY moade are supported 

### Borrowed files
- ImageLoader.h
- ImageLoader.cpp
- ImageLoaderMachO.h
- ImageLoaderMachO.cpp
- ImageLoaderMachOCompressed.h
- ImageLoaderMachOCompressed.cpp

All specific changes of original Apple code are under conditional compilation with 
`#if UNSIGN_TOLERANT` macros. All classes are moved into namespace "isolator" 
to avoid intersection with original symbols from libdyld.

The file `dyld_stubs.cpp` contains some utils and other stub functions to make this code 
compilable. Most of them has no implementation, just for signature compatibility.

### Link to original sources
https://opensource.apple.com/source/dyld/dyld-832.7.3
