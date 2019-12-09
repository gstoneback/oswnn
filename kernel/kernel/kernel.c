#include <stdio.h>
#include <kernel/tty.h>

void kernel_main() {
  tty_initialize();
  printf("OSWNN V0.01\nGABRIEL STONEBACK\n");
}
