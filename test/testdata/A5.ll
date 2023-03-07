; ModuleID = 'wpl.ll'
source_filename = "wpl.ll"

@const_str = private unnamed_addr constant [8 x i8] c"\22world\22\00", align 1

define i32 @program() {
  %s = alloca i8*, align 8
  store i8* getelementptr inbounds ([8 x i8], [8 x i8]* @const_str, i32 0, i32 0), i8** %s, align 8
  %s1 = alloca i8*, align 8
  %1 = load i8*, i8** %s, align 8
  store i8* %1, i8** %s1, align 8
  ret i32 0
}
