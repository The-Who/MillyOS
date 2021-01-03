FROM randomdude/gcc-cross-x86_64-elf

RUN apt update
RUN apt upgrade -y

RUN apt install nasm
RUN apt install xorriso
RUN apt install grub-pc-bin
RUN apt install grub-common

VOLUME  /root/env
WORKDIR /root/env
