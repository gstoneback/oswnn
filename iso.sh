#!/bin/bash
mkdir -p isodir/boot/grub
mv grub/* isodir/boot/grub
cp sysroot/boot/oswnn.kernel isodir/boot/oswnn.kernel
mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o oswnn.iso isodir
