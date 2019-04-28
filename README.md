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

~~~
