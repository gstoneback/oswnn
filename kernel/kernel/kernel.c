#include <stdio.h>
#include <kernel/tty.h>
char* logo = 
R"(   ____  ______       ___   ___   __
  / __ \/ ___/ |     / / | / / | / /
 / / / /\__ \| | /| / /  |/ /  |/ / 
/ /_/ /___/ /| |/ |/ / /|  / /|  /  
\____//____/ |__/|__/_/ |_/_/ |_/   )";
 
void kernel_main() {
  tty_initialize();
  printf("%s\n\nGABRIEL STONEBACK 2019\n", logo);
  for (int i = 0; 1; i++) {
    printf("%i\n", i);
  }
}
