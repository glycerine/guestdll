from ctypes import *
import _ctypes
fn = '/root/vol/go/pkg/linux_amd64_dynlink/libgithub.com-glycerine-guestdll-guest.so'
runtime = '/usr/local/go/pkg/linux_amd64_dynlink/libruntime,sync-atomic.so'
CDLL(runtime)
## OSError: /usr/local/go/pkg/linux_amd64_dynlink/libruntime,sync-atomic.so: undefined symbol: main.init
##lib = CDLL(fn)
#lib.guest.restype = c_int
#print lib.guest()
#_ctypes.dlclose(lib._handle)
