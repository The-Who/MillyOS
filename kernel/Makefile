OSNAME = MillyOS

GNUEFI = ../gnu-efi
OVMFDIR = ../OVMFbin
LDS = linker.ld
CC = gcc
LD = ld

CFLAGS = -ffreestanding -fshort-wchar
LDFLAGS = -T $(LDS) -static -Bsymbolic -nostdlib

SRCDIR := source
OBJDIR := libraries
BUILDDIR = ../binaries
BOOTEFI := $(GNUEFI)/x86_64/bootloader/main.efi

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.c)          
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DIRS = $(wildcard $(SRCDIR)/*)

kernel: $(OBJS) link

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ echo !==== COMPILING $^
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@
	
link:
	@ echo !==== LINKING
	$(LD) $(LDFLAGS) -o $(BUILDDIR)/kernel.elf $(OBJS)

setup:
	@mkdir $(BUILDDIR)
	@mkdir $(OBJDIR)

buildos:
	dd if=/dev/zero of=$(BUILDDIR)/$(OSNAME).iso bs=512 count=93750
	mformat -i $(BUILDDIR)/$(OSNAME).iso -f 1440 ::
	mmd -i $(BUILDDIR)/$(OSNAME).iso ::/EFI
	mmd -i $(BUILDDIR)/$(OSNAME).iso ::/EFI/BOOT
	mcopy -i $(BUILDDIR)/$(OSNAME).iso $(BOOTEFI) ::/EFI/BOOT
	mcopy -i $(BUILDDIR)/$(OSNAME).iso startup.nsh ::
	mcopy -i $(BUILDDIR)/$(OSNAME).iso $(BUILDDIR)/kernel.elf ::

run:
	qemu-system-x86_64 -drive file=$(BUILDDIR)/$(OSNAME).iso -m 256M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd" -net none
