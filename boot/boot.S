.set MAGIC,    0x1BADB002
.set FLAGS,    0
.set CHECKSUM, - (MAGIC + FLAGS)

.section .multiboot

.long MAGIC
.long FLAGS
.long CHECKSUM

stackBottom:

.skip 1024

stackTop:

.section .text
.global  start
.type    start, @function

start:
	mov $stackTop, %esp

	call startPoint
	cli

hltLoop:
	hlt
	jmp hltLoop

.size start, . - start
