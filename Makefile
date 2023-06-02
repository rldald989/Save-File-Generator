OBJS	= src/main.o
SOURCE	= src/main.cpp
HEADER	= 
OUT	= sfsys
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

src/main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp 


clean:
	rm -f $(OBJS) $(OUT)