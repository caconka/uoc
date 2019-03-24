OBJS = main.o
CFLAGS = -g -Wall

all: program

program: $(OBJS)
	gcc -o $@ $?

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -f program $(OBJS)

.PONY: clean
