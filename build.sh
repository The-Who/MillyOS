as --32 boot/boot.S -o boot/boot.o
gcc -m32 -c kernel/main.c -o kernel/main.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
ld -m elf_i386 -T linker.ld kernel/main.o boot/boot.o -o MillyOS.bin -nostdlib

grub-file --is-x86-multiboot MillyOS.bin

mkdir -p iso/boot/grub
cp MillyOS.bin iso/boot/MillyOS.bin
cp boot/grub.cfg iso/boot/grub/grub.cfg
grub-mkrescue -o MillyOS.iso iso

qemu-system-x86_64 -cdrom MillyOS.iso

rm boot/boot.o
rm kernel/main.o
rm -rf iso
rm MillyOS.bin
