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

void child(void *arg)
{
  printf(1, "Child process, argument: %d\n", *((int *)arg));
  // printf(1, "TID = %d\n", gettid());
  // printf(1, "PPID = %d\n", getppid());
  exit();
}

int main(int argc, char *argv[])
{
  int arg = 123;
  void *stack = (void *)sbrk(PGSIZE);
  stack = stack - 68;
  int tid;
  // printf(1, "Stack pointer: %d\n", (uint) stack);
  // printf(1, "Address of arg: %d\n", &arg);
  tid = clone(child, stack, (void *)&arg, CLONE_FILES);
  // printf(1, "Before Kill %d\n", tid);
  // sleep(5);
  // stack = stack - 68;

  /*kill*/
  // int ret_val = tkill(tid);
  // printf(1, "return value of tkill %d\n", ret_val);
  // if (ret_val == 0)
  // {
  //   printf(1,"Before join in tkill \n");
  //   int x = join(tid);
  //   printf(1, "Killed thread %d\n", x);
  //   exit();
  // }

  /*join*/

  printf(1, "Before Join returned %d \n", tid);
  join(tid);
  printf(1, "Join returned %d \n", tid);

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