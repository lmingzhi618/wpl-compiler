; ModuleID = 'wpl.ll'
source_filename = "wpl.ll"

@a = common global i32 1, align 4

define i32 @program() {
  ret i32 1
}
