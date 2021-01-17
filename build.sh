git clone https://github.com/The-Who/gnu-efi
git clone https://github.com/Absurdponcho/OVMFbin

cd kernel && make setup
make buildiso
make run
