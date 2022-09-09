obj-m := detect.o
KERNELBUILD :=/lib/modules/$(shell uname -r)/build

build:
	make -C $(KERNELBUILD) M=$(shell pwd) modules

clean:
	rm -rf *.ko *.mod.o *.o

test: build
	insmod detect.ko
	dmesg | tail -n 4
	rmmod detect

