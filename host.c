from ctypes import *
import _ctypes
lib = CDLL("./guest.so")
lib.fizzbuzz.restype = c_char_p
print lib.fizzbuzz()
print lib.fizzbuzz()
print lib.fizzbuzz()
print lib.fizzbuzz()
print lib.fizzbuzz()
print lib.fizzbuzz()
_ctypes.dlclose(lib._handle)