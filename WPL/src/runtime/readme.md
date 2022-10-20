You can create the foo.ll file using this command:

      clang -emit-llvm -S foo.c
Now, to create the runnable program, enter:

      clang -o foo foo.ll wpl_runtime.c
You can now run foo

      gpollice[2022]: foo 1 2 3
      The sum of the arguments is: 6
