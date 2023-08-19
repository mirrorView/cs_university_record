BUILD_DIR = ./build
SRC = .
AS = nasm 
CC = gcc
LD = ld

ENTRYPOINT:=0x10000


CFLAGS:= -m32 # 32 位的程序
CFLAGS+= -fno-builtin	# 不需要 gcc 内置函数
CFLAGS+= -nostdinc		# 不需要标准头文件
CFLAGS+= -fno-pic		# 不需要位置无关的代码  position independent code
CFLAGS+= -fno-pie		# 不需要位置无关的可执行程序 position independent executable
CFLAGS+= -nostdlib		# 不需要标准库
CFLAGS+= -fno-stack-protector	# 不需要栈保护
CFLAGS:=$(strip ${CFLAGS})

DEBUG:= -g
INCLUDE:=-I$(SRC)/include


############################################################### 汇编  #####################################################################

$(BUILD_DIR)/boot.bin:boot/boot.asm
	$(AS) -f bin $< -o $@	


$(BUILD_DIR)/loader.bin:boot/loader.asm
	$(AS) -f bin $< -o $@	

$(BUILD_DIR)/start.o: $(SRC)/kernel/start.asm
	nasm -f elf32 $< -o $@

$(BUILD_DIR)/io.o: $(SRC)/kernel/io.asm
	nasm -f elf32 $< -o $@

$(BUILD_DIR)/schedule.o: $(SRC)/kernel/schedule.asm
	nasm -f elf32 $< -o $@

$(BUILD_DIR)/handler.o: $(SRC)/kernel/handler.asm
	nasm -f elf32 $< -o $@

$(BUILD_DIR)/test_syscall.o: $(SRC)/kernel/test_syscall.asm
	nasm -f elf32 $< -o $@

$(BUILD_DIR)/kernel.bin: $(BUILD_DIR)/start.o \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/io.o \
	$(BUILD_DIR)/string.o \
	$(BUILD_DIR)/console.o \
	$(BUILD_DIR)/printk.o \
	$(BUILD_DIR)/vsprintf.o \
	$(BUILD_DIR)/assert.o	\
	$(BUILD_DIR)/debug.o	\
	$(BUILD_DIR)/global.o	\
	$(BUILD_DIR)/schedule.o	\
	$(BUILD_DIR)/task.o	\
	$(BUILD_DIR)/interrupt.o	\
	$(BUILD_DIR)/handler.o	\
	$(BUILD_DIR)/stdlib.o	\
	$(BUILD_DIR)/clock.o	\
	$(BUILD_DIR)/time.o	\
	$(BUILD_DIR)/rtc.o	\
	$(BUILD_DIR)/memory.o	\
	$(BUILD_DIR)/bitmap.o	\
	$(BUILD_DIR)/gate.o	\
	$(BUILD_DIR)/test_syscall.o	\
	$(BUILD_DIR)/syscall.o	\
	$(BUILD_DIR)/list.o	\
	$(BUILD_DIR)/thread.o	\
	$(BUILD_DIR)/mutex.o	\
	$(BUILD_DIR)/keyboard.o	\
	$(BUILD_DIR)/fifo.o	\
	$(BUILD_DIR)/printf.o	\
	$(BUILD_DIR)/arena.o	\
	$(BUILD_DIR)/ide.o	\

	ld -m elf_i386 -static $^ -o $@ -Ttext $(ENTRYPOINT)

$(BUILD_DIR)/system.bin: $(BUILD_DIR)/kernel.bin
	objcopy -O binary $< $@

$(BUILD_DIR)/system.map: $(BUILD_DIR)/kernel.bin
	nm $< | sort > $@



############################################################## c 代码 #########################################################################
$(BUILD_DIR)/main.o: $(SRC)/kernel/main.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@	

$(BUILD_DIR)/string.o: $(SRC)/lib/string.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@	

$(BUILD_DIR)/console.o: $(SRC)/kernel/console.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@	

$(BUILD_DIR)/printk.o: $(SRC)/kernel/printk.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@	

$(BUILD_DIR)/vsprintf.o: $(SRC)/lib/vsprintf.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@	

$(BUILD_DIR)/assert.o: $(SRC)/kernel/assert.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@	

$(BUILD_DIR)/debug.o: $(SRC)/kernel/debug.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/global.o: $(SRC)/kernel/global.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@	

$(BUILD_DIR)/task.o: $(SRC)/kernel/task.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@		

$(BUILD_DIR)/interrupt.o: $(SRC)/kernel/interrupt.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/stdlib.o: $(SRC)/lib/stdlib.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/clock.o: $(SRC)/kernel/clock.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/time.o: $(SRC)/kernel/time.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/rtc.o: $(SRC)/kernel/rtc.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/memory.o: $(SRC)/kernel/memory.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/bitmap.o: $(SRC)/kernel/bitmap.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/gate.o: $(SRC)/kernel/gate.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/syscall.o: $(SRC)/kernel/syscall.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/list.o: $(SRC)/kernel/list.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/thread.o: $(SRC)/kernel/thread.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/mutex.o: $(SRC)/kernel/mutex.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/keyboard.o: $(SRC)/kernel/keyboard.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/fifo.o: $(SRC)/kernel/fifo.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/printf.o: $(SRC)/lib/printf.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/arena.o: $(SRC)/kernel/arena.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/ide.o: $(SRC)/kernel/ide.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

############################################################## 定义函数 加载程序到硬盘 #####################################################
.PHONY:mk_dir hd clean build all run  

mk_dir:
	if [ ! -d $(BUILD_DIR) ];then mkdir $(BUILD_DIR);fi

hd:
	dd if=$(BUILD_DIR)/boot.bin of=master.img bs=512 count=1  conv=notrunc
	dd if=$(BUILD_DIR)/loader.bin of=master.img bs=512 count=4 seek=2  conv=notrunc
	test -n "$$(find $(BUILD_DIR)/system.bin -size -100k)"
	dd if=$(BUILD_DIR)/system.bin of=master.img bs=512 count=200 seek=10 conv=notrunc

build:$(BUILD_DIR)/boot.bin \
	$(BUILD_DIR)/loader.bin \
	$(BUILD_DIR)/start.o \
	$(BUILD_DIR)/io.o \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/console.o  \
	$(BUILD_DIR)/string.o  \
	$(BUILD_DIR)/printk.o	\
	$(BUILD_DIR)/vsprintf.o \
	$(BUILD_DIR)/assert.o	\
	$(BUILD_DIR)/debug.o	\
	$(BUILD_DIR)/global.o	\
	$(BUILD_DIR)/schedule.o	\
	$(BUILD_DIR)/task.o	\
	$(BUILD_DIR)/interrupt.o	\
	$(BUILD_DIR)/handler.o	\
	$(BUILD_DIR)/stdlib.o	\
	$(BUILD_DIR)/clock.o	\
	$(BUILD_DIR)/time.o	\
	$(BUILD_DIR)/rtc.o	\
	$(BUILD_DIR)/memory.o	\
	$(BUILD_DIR)/bitmap.o	\
	$(BUILD_DIR)/gate.o	\
	$(BUILD_DIR)/test_syscall.o	\
	$(BUILD_DIR)/syscall.o	\
	$(BUILD_DIR)/list.o	\
	$(BUILD_DIR)/thread.o	\
	$(BUILD_DIR)/mutex.o	\
	$(BUILD_DIR)/keyboard.o	\
	$(BUILD_DIR)/fifo.o	\
	$(BUILD_DIR)/printf.o	\
	$(BUILD_DIR)/arena.o	\
	$(BUILD_DIR)/ide.o	\
	$(BUILD_DIR)/kernel.bin \
	$(BUILD_DIR)/system.bin \
	$(BUILD_DIR)/system.map
	

clean:
	cd $(BUILD_DIR) && rm -f ./*

all:clean mk_dir build hd

run:
	bochs -q -f /home/gc/Desktop/workspace/cs_university_record/os_learn/src/bochsrc.disk 

debug:
	bochs -q -f /home/gc/Desktop/workspace/cs_university_record/os_learn/src/bochsrc.gdb 