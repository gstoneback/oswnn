#!/bin/bash
set -e
. ./build.sh

mkdir -p isodir/boot
cp -a grub isodir/boot
cp sysroot/boot/oswnn.kernel isodir/boot/oswnn.kernel
mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o oswnn.iso isodir
