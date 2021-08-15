APPNAME += main
SRCS += main.c
LDFLAGS += -ldir

all:
	gcc $(SRCS) -o $(APPNAME) $(LDFLAGS)

clean:
	rm -f *.o $(APPNAME)