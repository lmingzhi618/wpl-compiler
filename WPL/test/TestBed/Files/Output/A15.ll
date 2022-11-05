; ModuleID = 'wpl.ll'
source_filename = "wpl.ll"

define i32 @program() {
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %1 = and i1 true, false
  %2 = zext i1 %1 to i32
  %cond = icmp eq i32 %2, 1
  br i1 %cond, label %then, label %merge

then:                                             ; preds = %0
  store i32 1, i32* %i, align 4
  br label %merge

merge:                                            ; preds = %then, %0
  %3 = load i32, i32* %i, align 4
  ret i32 %3
}
