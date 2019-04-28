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

~~~
