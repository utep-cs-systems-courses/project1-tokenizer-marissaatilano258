OBJS=tokenizer.o history.o uimain.o

CFLAGS=-g -O3

all: tokenizeInput

tokenizeInput: $(OBJS)
	cc -o tokenizeInput $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokenizeInput

run:tokenizeInput
	./tokenizeInput
