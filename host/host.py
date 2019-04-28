from ctypes import *
import _ctypes

runtimefn = '/usr/local/go/pkg/linux_amd64_dynlink/libruntime,sync-atomic.so'
rt = CDLL(runtimefn)

rtinit = getattr(rt, "runtime.init")
rtinit()
rtmain = getattr(rt, "runtime.main")
rtmain()

guestfn = '/root/vol/go/pkg/linux_amd64_dynlink/libgithub.com-glycerine-guestdll-guest.so'
g = CDLL(guestfn)
g.guest.restype = c_int
print g.guest()
_ctypes.dlclose(g._handle)
