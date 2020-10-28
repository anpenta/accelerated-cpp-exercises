CC = g++
CFLAGS = -g -std=c++17
SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))

.PHONY: all clean

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	rm -f $(PROGS)
