CC = g++
CXXFLAGS = -g -O2
OBJS = ppm.o main.o
TARGET = ../bin/main.out

%.o: %.cc
	$(CC) $(CXXFLAGS) -c $<

main : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
