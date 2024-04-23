.phony: all clean build

target := ssh_server
CC := gcc
RM := rm -rf
CP := cp -rf
TYPE_SRC := .c

SRCS := $(wildcard *$(TYPE_SRC))
	
CFLAGS := -lutil -lpthread -lssh  -Wall -g 


all:$(target) 
	@echo "complie succeed"
	
$(target):$(SRCS)
	@echo "complie $@" 
	$(CC) $^ -o $@ $(CFLAGS) 

clean:
	$(RM) $(target)
rebuild: clean all
	@echo "rebuild succeed."
