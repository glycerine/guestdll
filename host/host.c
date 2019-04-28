#include "stdlib.h"
#include "stdio.h"
#include "dlfcn.h"

// NB change this to reflect the path to your runtime library.
const char* runtimeFn = "/usr/local/go/pkg/linux_amd64_dynlink/libruntime,sync-atomic.so";

int main() {
  void *rtHandle;
  void (*runtimeStart)();
  char *error;
  
  printf("host.c main has begun.\n");
  rtHandle = dlopen(runtimeFn, RTLD_LAZY | RTLD_GLOBAL | RTLD_NODELETE);
  if (!rtHandle) {
    fprintf(stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }
  dlerror();    /* Clear any existing error */  
  runtimeStart = dlsym(rtHandle, "_rt0_amd64_linux");

  error = dlerror();
  if (error != NULL) {
    fprintf(stderr, "%s\n", error);
    exit(EXIT_FAILURE);
  }
  printf("good: about to invoke runtimeStart().\n");    
  runtimeStart();
  printf("host.c main is done.\n");
  return 0;
}

void init() {
  printf("host.c init is run.\n");  
}
