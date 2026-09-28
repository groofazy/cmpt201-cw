#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void sig_handler(int signum) { write(STDOUT_FILENO, "TEST\n", 5); }

int main() {
  struct sigaction act;
  act.sa_handler = sig_handler;
  act.sa_flags = 0;

  // clear .sa_mask
  sigemptyset(&act.sa_mask);
}
