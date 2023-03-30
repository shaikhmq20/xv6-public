#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "mmu.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"
#include "spinlock.h"
#include "flag.h"

void child(void *arg) {
  printf(1, "Child process, argument: %d\n", *((int*)arg));
  exit();
}

int main(int argc, char *argv[]) {
  int arg = 123;
  void *stack = (void*) sbrk(PGSIZE);
  stack = stack - 68;
  // printf(1, "Stack pointer: %d\n", (uint) stack);
  // printf(1, "Address of arg: %d\n", &arg);
  clone(child, stack, (void *)&arg, CLONE_FILES);
  wait();
  // if (pid == 0) {
  //   // Child process, call child function
  //   child(&arg);
  // } else if (pid > 0) {
  //   // Parent process, wait for child to exit
  //   wait();
  //   printf(1, "Parent process, child pid: %d\n", pid);
  // } else {
  //   // Error
  //   printf(1, "Error: clone failed\n");
  // }

  exit();
}