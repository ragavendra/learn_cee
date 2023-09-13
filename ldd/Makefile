# If KERNELRELEASE is defined, we've been invoked from the
# kernel build system and can use its language.
ifneq ($(KERNELRELEASE),)
	obj-m := hello.o
	# Otherwise we were called directly from the command
	# line; invoke the kernel build system.
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	# KERNELDIR ?= /lib/modules/5.15.131/build
PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
# make -C /run/media/scion/4b29c2d1-0afc-4483-9ae7-029e32ec28b8/repos/linux-5.15.131 M=`pwd` modules
# install linux-headers for that uname -r and reboot for uname -r to match it, now drivers can be written
