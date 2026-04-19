CC = gcc
CFLAGS = -Wall
FILES = PacMan.c map.c PM.c
HEADERS = 
TARGET = p


$(TARGET): $(FILES) $(HEADERS)
	$(CC) $(FLAGS) -o $@ $^

all: $(TARGET)

clean:
	$(RM) $(TARGET)
