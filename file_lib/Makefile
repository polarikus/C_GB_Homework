SRCS += dir.c
LIBNAME += libdir.so

all:
	gcc $(SRCS) -o $(LIBNAME) -shared -fPIC

install:
	cp $(LIBNAME) /usr/lib
	cp dir.h /usr/include

uninstall:
	rm -f /usr/lib/$(LIBNAME) /usr/include/dir.h

clean:
	rm -f $(LIBNAME) *.o