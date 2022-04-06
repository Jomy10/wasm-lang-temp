;; examples of the functions.md
(module
    ;; adding
    (export "add" (func $add))
    (func $add (param $lhs i32) (param $rhs i32) (result i32)
        local.get $lhs
        local.get $rhs
        i32.add
    )
    ;; storing variable
    (export "storeExample" (func $storeExample))
    (func $storeExample (param $i i32) (result i32) (local $someVar i32)
        local.get $i
        local.set $someVar
        local.get $someVar
    )
    ;; simple program
    (export "myFunc" (func $myFunc))
    (func $myFunc (param $i i32) (result i32) 
      (local $add i32) (local $sub i32)
        ;; let add = i = 7
        local.get $i
        i32.const 7
        i32.add
        local.set $add

        ;; let sub = add - i
        local.get $add
        local.get $i
        i32.sub
        local.set $sub

        ;; return sub
        local.get $sub
    )
)
