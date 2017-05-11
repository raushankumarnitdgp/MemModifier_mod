CONFIG_MODULE_SIG=n
CONFIG_MODULE_SIG_ALL=n
obj-m += Mem_Modifier.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
