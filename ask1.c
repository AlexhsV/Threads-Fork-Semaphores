/* Includes */
#include <stdio.h>    /* Input/Output */
#include <unistd.h>   /* Symbolic Constants */
#include <sys/wait.h> /* Wait for Process Termination */

int main() {
  pid_t p0, p1, p2, p3, p4, p5, p6;

  p1 = fork();  //creating a new process
  if (p1 == 0) { // child process P1

    p3 = fork(); //creating a new process
    if (p3 == 0) { // child process P3
      printf("Hello from process P3, PID = %d, PPID = %d\n", getpid(), getppid());
    }
    else { // parent process P1
      waitpid(p3, NULL, 0); // wait for completion of P3
      printf("Hello from process P1, PID = %d, PPID = %d\n", getpid(), getppid());
    }
  }
  else { // parent process P0
    p0 = fork(); //creating a new process
    if (p0 == 0) { // child process P2
      p2 = fork(); //creating a new process
      if (p2 == 0) { // child process P4
        printf("Hello from process P4, PID = %d, PPID = %d\n", getpid(), getppid());
      }
      else { // parent process P2
        p5 = fork(); //creating a new process
        if (p5 == 0) { // child process P5
          printf("Hello from process P5, PID = %d, PPID = %d\n", getpid(), getppid());
          p6 = fork(); //creating a new process
          if (p6 == 0) { // child process P6
            printf("Hello from process P6, PID = %d, PPID = %d\n", getpid(), getppid());
          }
        
        }
        else { // parent process P2
          wait(NULL); // wait for completion of at least one child process
          printf("Hello from process P2, PID = %d, PPID = %d\n", getpid(), getppid());
        }
      }
    }
    else { // parent process P0
          waitpid(p1, NULL, 0); // wait for completion of p1
          waitpid(p2, NULL, 0); // wait for completion of p2
          waitpid(p6, NULL, 0); // wait for completion of p6
          waitpid(p4, NULL, 0); // wait for completion of p4
          printf("Hello from process P0, PID = %d, PPID = %d\n\n", getpid(), getppid());
          execl("/bin/cat", "cat", "ask1.c", NULL); // replacing P0 process with cat command
        }
  }
  return 0;
}