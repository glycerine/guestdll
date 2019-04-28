# guestdll
go building reloadable (dlclose supported) dlls with shared runtime

~~~
go install -buildmode=shared std
go install -buildmode=shared runtime sync/atomic
go install -buildmode=shared -linkshared github.com/glycerine/guestdll/guest

~~~