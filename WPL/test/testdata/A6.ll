; ModuleID = 'wpl.ll'
source_filename = "wpl.ll"

@str = private unnamed_addr constant [12 x i8] c"hello world\00", align 1
@str.1 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @program() {
  %s = alloca i8*, align 8
  store i8* getelementptr inbounds ([12 x i8], [12 x i8]* @str, i32 0, i32 0), i8** %s, align 8
  %1 = load i8*, i8** %s, align 8
  %2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @str.1, i32 0, i32 0), i8* %1)
  ret i32 0
}
