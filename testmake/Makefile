CC = g++

CFLAGS  = -std=c++11

INCLUDES = -I../include

LFLAGS = -L../lib

#LIBS =

SRCS = main.cpp include.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = main

.PHONY: depend clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(TARGET)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
