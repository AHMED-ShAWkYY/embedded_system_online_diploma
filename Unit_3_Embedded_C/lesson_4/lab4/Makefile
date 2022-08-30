#@copyright ahmed shawki

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS= -I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
project_name=learn-in-depth-cortex-m4
all: $(project_name).bin
	@echo "<<<<<<<<<<<<<<<build is done>>>>>>>>>>>>>>>"

%.o: %.s
	$(CC)as.exe $< $(CFLAGS) -o $@
	
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@	

	
$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=mapfile.map
	cp $(project_name).elf $(project_name).axf
	
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@	

clean_all: 
	rm *.o *.bin *.elf *.axf
	@echo "build is clean"

clean:
	rm *.bin *.elf *.axf
	