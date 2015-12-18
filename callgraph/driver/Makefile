obj-m = birria.o
KVERSION = $(shell uname -r)
ccflags-y =-g -O0


all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD)  modules


clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
