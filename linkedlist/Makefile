CC = gcc
CFLAGS = -I .
TARGET = linkedlist.out
OBJ = $(patsubst %.c, %.o, $(wildcard *.c))
DEPS = $(wildcard *.h)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	rm -rf *.o *.gch $(TARGET)

valgrind:
	make $(TARGET)
	valgrind --leak-check=yes ./$(TARGET)
