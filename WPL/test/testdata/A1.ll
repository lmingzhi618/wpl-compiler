; ModuleID = 'wpl.ll'
source_filename = "wpl.ll"

@const_str = private unnamed_addr constant [8 x i8] c"\22hello\22\00", align 1
@gs = global i8* getelementptr inbounds ([8 x i8], [8 x i8]* @const_str, i32 0, i32 0)
@gn = common global i32 666, align 4

define i32 @program() {
  %s = alloca i8*, align 8
  %1 = load i8*, i8** @gs, align 8
  store i8* %1, i8** %s, align 8
  %ret = alloca i32, align 4
  store i32 666, i32* %ret, align 4
  %2 = load i32, i32* %ret, align 4
  ret i32 %2
}
