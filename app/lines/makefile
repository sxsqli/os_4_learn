c-src = lines.c
c-obj = $(c-src:%.c=%.o)

target = lines
target-elf = $(target).elf
target-bin = $(target).bin

extlibs = ../out/libc.o
extlibs += ../../libccommon/libccommon.o

default: all

%.o: %.c
	@echo " 	[CC] 	$<"
	@gcc -c -m32 -fno-builtin -fno-stack-protector $< -o $@


all: $(c-obj)
	@echo " 	[LD] 	$(target)"
	@ld $(extlibs)  $(c-obj) -T linker.ld -o $(target-elf)
	@echo " 	[GENAPP] 	$(target-bin)"
	@objcopy -S -O binary $(target-elf) $(target-bin)
	@readelf -S $(target-elf) | awk '{ print $$3,$$5,$$7 }' |grep "^\." > $(target).elfinfo
	@../genexec $(target)
	@cp $(target-bin) ../out/

clean:
	rm -rf *.o *.bin *.elf*
