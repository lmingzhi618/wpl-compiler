# WPL -- reference compiler application

## Setup

1. You have already unzipped the archive and are looking at this file. We will call this directory `PROJECT_ROOT`.

2. Copy or move the `antlr/antlr4-cpp-runtime.zip` archive to a separate directory. You could unzip it in place, but that introduces more complexity than you want. The directory where you unzipped it we will call `ANTLR_ROOT`.

3. In a terminal, go to the `ANTLR_ROOT` the following commands in order (this will take a few minutes).
  - `cmake -S . -B build`
  - `cmake --build build`

4. Go to the `build` directory and run the command `ctest`. This will run the tests and you should get no errors.

5. Go to the `ANTLR_ROOT/dist` directory. There will be one or more libraries there. Depending upon your platform, these might have different names. You want to take the one that is a static library and move it to the `PROJECT_ROOT/antlr/lib`. If the name of the library is not `libantlr4-runtime.a`, then modify the `PROJECT_ROOT/src/cmake/antlr.cmake` by changing the library name. NOTE: There is a `libantlr4-runtime.a` in the directory. You should overwrite this or remove it.

6. If you do not have the ability to run a `bash` script then you need to modify the `PROJECT_ROOT/src/lexparse/generate.sh` script. See instructions below. If you can run `bash` scripts you can skip this step.

7. Now go to the `PROJECT_ROOT` directory. and executed the following commands in order:
  - `cmake -S . -B build`
  - `cmake --build build` 
  - `cmake -- install build`
  - `install/calculator`

You should see output of: `<EOF> <EOF>`. If you do, congratulations, you're all set. If there are errors you need to do some debugging. Ask for help from the staff or on the Slack #toolchain channel.

## Symbol table hierarchy
### Necessary operations
* Look up an ID
  - in current scope
  - in current and enclosing scopes
* Insert a ID(and symbol)
* Enter a new scope
* Exit a new scope


### Symbol table requirements
* Fast lookup and retrival of symbols
* Allow multiple definitions of an ID in the source language
  - The language may or may not dictate that one instance hides another
* Support dynamic and/or static scoping
* Support various definition paradigms

### Two symbol table implementations
#### Stack
* When a new scope is needed, create an put on top of the stack
* After the code for the scope has been processed, pop it off the symbol table stack
* Once a scope has been popped, it is no longer accessible

#### (Flattened)Tree
* Array or list
* Pointer from child tree to parent
* Scopes are always accessible



## Symbol Table Data Structure
The base type of function is the return type
The base type of precedure is undefined
The base type of array is the element type(length is used on array)
The base type of scalar is type;


## Functionalities
- Implement standard and inline comments.   
- Compile a single int program() function that can be compiled by llc and then assembled with the runtime library by clang. 
  A single int program() means that you do not have to implement functions and procedures in this level except for this one. 

- All variables must be declared individually and typed.
- Only one variable can be declared in a variable declaration (i.e., int x, y; is illegal).
- Variable definition is not allowed. That is you cannot assign a value to a variable in the declaration (int a <- 1; is illegal).
- No string or boolean types, just integers.
- No function or procedure calls.
- No arrays.
- Only integer arithmetic: +, -, *, /, and unary -    
- Parentheses to change the precedence.               
- statements: 
  assignment  
  condition   
  block       
  return.     
- Implement all of the C grade requirements. 
- Be able to call functions and procedures
  from the standard library (e.g. printf) and from the WPL runtime library (e.g. getArgc).
- Allow multiple variables to be declared in a declaration (int a, b, c;).  
- Implement variable initialization (int a <- 42;).   
- Implement string and boolean types.                 
- Nested inline comments.                     ???
- Boolean (relational expressions). No logical expressions (& and |). 
- Implement loop statements.                          
- Implement all of B grade requirements.
- Implement logical expressions.                     
- Implement functions and procedures completely (define your own and call any).
- Type inference (var x;).
- Implement select statements                        
- Implement arrays                                   


grun WPL tokens -tokens
grun WPL tokens -tokens test.txt

grun WPL compilationUnit -gui
> int a; int func program() {a <- 1; return 0;}


### phi 指令用于实现 PHI 节点。

example
``` LLVM
Loop:       ; Infinite loop that counts from 0 on up...
  %indvar = phi i32 [ 0, %LoopHeader ], [ %nextindvar, %Loop ]
  %nextindvar = add i32 %indvar, 1
  br label %Loop
```
在运行时，phi 指令根据“在当前 block 之前执行的是哪一个 predecessor(前任) block”来得到相应的值。

以上面示例中的 phi 指令为例，如果当前 block 之前执行的是 LoopHeader，则该 phi 指令的值是 0，而如果是从 Loop label 过来的，则该 phi 指令的值是 %nextindvar。

在 phi 指令的语法中，后面是一个列表，列表中的每个元素是一个 value/label 对，每个 label 表示一个当前 block 的 predecessor block，phi 指令就是根据 label 选相应的 value。

phi 指令必须在 basic block 的最前面，也就是在一个 basic block 中，在 phi 指令之前不允许有非 phi 指令。

