# Threads-Fork-Semaphores
ask1:
Write a C program with the appropriate fork() commands to create a total (including the main program) of seven processes, with the following kinship structure (tree):
![image](https://user-images.githubusercontent.com/98179885/210116201-3e992f1e-0366-4b50-a2e3-1db42f7669d8.png)

As a main part of its job, each Pi process simply prints a message on the screen that
stating its name (Pi), its PID (Process ID) and its PPID (Parent Process ID). Your program
additionally include appropriate wait commands (system calls wait() and/or
waitpid())) to satisfy the following constraints:
1. The P2 process must wait for the
at least one of its immediate children to complete; and
2. Process P1 must wait for the completion of at least one of its first two children before executing its main task.
of process P3.
Finally, P0 upon completion of its execution should be replaced (using one of the family of calls
system exec()) by the cat command, which will print the source code of your program.



ask2:
Write a C program, which will use the POSIX Threads library, running
which will result in the sequence being printed iteratively:

Hello there wonderful world!

Hello there wonderful world!

Hello there wonderful world!

...


To achieve the above, you will need to create 4 different threads in your program, each of them
of which the first one will continuously print "Hello ", the second one will continuously print "there ", the third one
will constantly print "wonderful " and the fourth will constantly print "world!". It should
synchronize the threads appropriately with each other using flags.
