OBJS=analyzeInput.o uimain.o

CFLAGS=-g

all: tokenizeInput

tokenizeInput: $(OBJS)
	cc -o tokenizeInput $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokenizeInput

run:tokenizeInput
	./tokenizeInput
