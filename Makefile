CFLAGS += -Wall -Werror -std=gnu11 -O2
LDFLAGS += -lm

TARGET = test

SRCS = test.c tests/src/stack.c src/dummytest.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
