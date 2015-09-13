CC = g++
CFLAGS = -O3 -ffast-math -std=c++11 -Wall


all: main server client
	$(CC) $(CFLAGS) main.o server.o client.o -o chRtik
main:
	$(CC) $(CFLAGS) -c main.cpp
server:
	$(CC) $(CFLAGS) -c server.cpp
client:
	$(CC) $(CFLAGS) -c client.cpp
mrproper:
	rm *.o

