.PHONY: all
all:
	go install -buildmode=shared runtime sync/atomic
	go install -buildmode=shared std  # may or may not be needed
	gcc -g -o host host.c -ldl
	./host
