# guestdll
go building reloadable (dlclose() supported) dlls with shared runtime

~~~
go install -buildmode=shared std  # may or may not be needed
go install -buildmode=shared runtime sync/atomic
go install -buildmode=shared -linkshared github.com/glycerine/guestdll/guest

# the last 'go install' puts the .so shared library into
cd ${GOPATH}/pkg/linux_amd64_dynlink/libgithub.com-glycerine-guestdll-guest.so

# the runtime .so got built and saved here:
${GOROOT}/pkg/linux_amd64_dynlink/libruntime,sync-atomic.so


Current sticking point:

Trying to load the runtime (or stdlib) references a main.init function, which
is not found, when loading is attempted (here via python)

from ctypes import *
import _ctypes
fn = '/root/vol/go/pkg/linux_amd64_dynlink/libgithub.com-glycerine-guestdll-guest.so'
runtime = '/usr/local/go/pkg/linux_amd64_dynlink/libruntime,sync-atomic.so'
CDLL(runtime)
## OSError: /usr/local/go/pkg/linux_amd64_dynlink/libruntime,sync-atomic.so: undefined symbol: main.init

## update: we hacked around this temporarily by commenting out the
## references to main_init and main_main in runtime/proc.go and rebuilding
## both runtime and stdlib.  We will probably have to inject a small
## stub DLL that just has these two functions or otherwise allow
## these references to be satisfied.

next issue: how to we initialize the Go runtime?  When we
examined a Go binary on linux, the ELF header tells us that
the _rt0_amd64_linux function is the initializer, or first
run entry point function. So we constructed guestdll/host/host.c
which dynamically loads the runtime .so and then tries
to call _rt0_amd64_linux(). However this currently segfaults
and we are investigating why.

~~~
