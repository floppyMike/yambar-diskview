CC ?= gcc
CFLAGS = -Wall -Wextra -Ofast
LDFLAGS =

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = yambar-diskview

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
