FREEOBJS=\
stdio/printf.o \
stdio/putchar.o \
stdio/puts.o \
stdlib/abort.o \
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/memset.o \
string/strlen.o \

LIBK_OBJS=$(FREEOBJS:.o=.libk.o)

BINARIES=libk.a
.PHONY: all clean
.SUFFIXES: .o .libk.o .c .S

all: $(BINARIES)

libk.a: LIBK_OBJS
	$(AR) rcs $@ $(LIBK_OBJS)
