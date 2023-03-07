; ModuleID = 'wpl.ll'
source_filename = "wpl.ll"

declare i32 @getArgCount()

define void @p() {
  %i = alloca i32, align 4
  %1 = call i32 @getArgCount()
  store i32 %1, i32* %i, align 4
  ret void
}

define i32 @program() {
  call void @p()
  ret i32 0
}
