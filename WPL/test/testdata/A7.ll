; ModuleID = 'wpl.ll'
source_filename = "wpl.ll"

define i32 @sum(i32 %a, i32 %b) {
  %a1 = alloca i32, align 4
  store i32 %a, i32* %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, i32* %b2, align 4
  %1 = load i32, i32* %a1, align 4
  %2 = load i32, i32* %b2, align 4
  %3 = add nsw i32 %1, %2
  ret i32 %3
}

define i32 @program() {
  %i = alloca i32, align 4
  %1 = call i32 @sum(i32 40, i32 2)
  store i32 %1, i32* %i, align 4
  %2 = load i32, i32* %i, align 4
  ret i32 %2
}
