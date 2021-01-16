# Prerequisites
GCC,
Make,
Git.

For install all digit on the terminal this:
* For Debian/Ubuntu or derivates:

`sudo apt update`

`sudo apt upgrade -y`

`sudo apt install build-essential mtools qemu qemu-kvm git`

* For Arch or derivates:

`sudo pacman -Syu`

`sudo pacman -S base-devel qemu git`

# Preparing the workspace
Go to the main directory, right click and go to "open in terminal".
And digit 

`git clone https://github.com/The-Who/gnu-efi && git clone https://github.com/Absurdponcho/OVMFbin`.

Now, you have the repositories, for make gnu-efi type this:

`cd gnu-efi && make`

# Building the source
Go to the kernel directory, right click and go to "open in terminal".

Type this:

`cd .. && sh build.sh`

Well, now you can use the operating system!!
