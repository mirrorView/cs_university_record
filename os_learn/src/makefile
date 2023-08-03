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

$(BUILD_DIR)/kernel.bin: $(BUILD_DIR)/start.o $(BUILD_DIR)/main.o $(BUILD_DIR)/io.o $(BUILD_DIR)/string.o $(BUILD_DIR)/console.o
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


############################################################## 定义函数 加载程序到硬盘 #####################################################
.PHONY:mk_dir hd clean build all run  

mk_dir:
	if [ ! -d $(BUILD_DIR) ];then mkdir $(BUILD_DIR);fi

hd:
	dd if=$(BUILD_DIR)/boot.bin of=master.img bs=512 count=1  conv=notrunc
	dd if=$(BUILD_DIR)/loader.bin of=master.img bs=512 count=4 seek=2  conv=notrunc
	dd if=$(BUILD_DIR)/system.bin of=master.img bs=512 count=200 seek=10 conv=notrunc

build:$(BUILD_DIR)/boot.bin $(BUILD_DIR)/loader.bin $(BUILD_DIR)/start.o $(BUILD_DIR)/io.o $(BUILD_DIR)/main.o $(BUILD_DIR)/console.o  $(BUILD_DIR)/string.o  $(BUILD_DIR)/kernel.bin $(BUILD_DIR)/system.bin $(BUILD_DIR)/system.map
	

clean:
	cd $(BUILD_DIR) && rm -f ./*

all:clean mk_dir build hd

run:
	bochs -q -f /home/gc/Desktop/workspace/cs_university_record/os_learn/src/bochsrc.disk 

debug:
	bochs -q -f /home/gc/Desktop/workspace/cs_university_record/os_learn/src/bochsrc.gdb 