; ModuleID = 'wpl.ll'
source_filename = "wpl.ll"

define i32 @program() {
  %iarray = alloca [5 x i32], align 4
  %1 = getelementptr [5 x i32], [5 x i32]* %iarray, i32 0, i32 3
  store i32 3, i32* %1, align 4
  %2 = getelementptr [5 x i32], [5 x i32]* %iarray, i32 0, i32 3
  %3 = load i32, i32* %2, align 4
  ret i32 %3
}
