INCLUDE = ../include
LIB = ../lib
MODULES = ../modules


CC = gcc

OBJS = game.o $(MODULES)/interface.o $(LIB)/libraylib.a
EXEC = game
CFLAGS = -Wall -g -I$(INCLUDE) 
LDFLAGS = -lm

include $(LIB)/libraylib.mk

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

$(LIB)/%.a:
	$(MAKE) -C $(LIB) $*.a
	
run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

