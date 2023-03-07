; ModuleID = 'wpl.ll'
source_filename = "wpl.ll"

define i32 @program() {
  %b = alloca i1, align 1
  store i1 true, i1* %b, align 1
  %b1 = alloca i1, align 1
  %1 = load i1, i1* %b, align 1
  %cond = icmp eq i1 %1, false
  %2 = select i1 %cond, i1 true, i1 false
  store i1 %2, i1* %b1, align 1
  %b2 = alloca i1, align 1
  %3 = load i1, i1* %b1, align 1
  %cond1 = icmp eq i1 %3, false
  %4 = select i1 %cond1, i1 true, i1 false
  store i1 %4, i1* %b2, align 1
  %r = alloca i32, align 4
  store i32 0, i32* %r, align 4
  %5 = load i1, i1* %b, align 1
  %6 = zext i1 %5 to i32
  %cond2 = icmp eq i32 %6, 1
  br i1 %cond2, label %then, label %merge

then:                                             ; preds = %0
  %7 = load i32, i32* %r, align 4
  %8 = add nsw i32 %7, 1
  store i32 %8, i32* %r, align 4
  br label %merge

merge:                                            ; preds = %then, %0
  %9 = load i1, i1* %b1, align 1
  %10 = zext i1 %9 to i32
  %cond5 = icmp eq i32 %10, 1
  br i1 %cond5, label %then3, label %merge4

then3:                                            ; preds = %merge
  %11 = load i32, i32* %r, align 4
  %12 = add nsw i32 %11, 2
  store i32 %12, i32* %r, align 4
  br label %merge4

merge4:                                           ; preds = %then3, %merge
  %13 = load i1, i1* %b2, align 1
  %14 = zext i1 %13 to i32
  %cond8 = icmp eq i32 %14, 1
  br i1 %cond8, label %then6, label %merge7

then6:                                            ; preds = %merge4
  %15 = load i32, i32* %r, align 4
  %16 = add nsw i32 %15, 4
  store i32 %16, i32* %r, align 4
  br label %merge7

merge7:                                           ; preds = %then6, %merge4
  %17 = load i32, i32* %r, align 4
  ret i32 %17
}
