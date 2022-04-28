# Syntax and underlying wasm repr

## adding
```
func add(lhs: i32, rhs: i32) -> i32 {
    lhs + rhs
}
```

```wat
(func $add (param $lhs i32) (param $rhs i32) (result i32)
    local.get $lhs
    local.get $rhs
    i32.add
)
```

OR

```wat
(func $add (param $lhs i32) (param $rhs i32) (result i32)
    (i32.add
        (local.get $lhs)
        (local.get $rhs)
    )
)
```

## storing variable

```
func storeExample(i: i32) -> i32 {
    let someVar = i
    someVar
}
```


```wat
(func $storeExample (param $i i32) (result i32) (local $someVar i32)
    local.get $i
    local.set $someVar
    local.get $someVar
)
```

## public
```
pub func someFunc() {}
```

```wat
(export "someFunc" (func $someFunc))
(func $somFunc)
```

## simple program
```
func myFunc(i: i32) -> i32 {
    let add = i + 7
    let sub = add - i
    return sub
}
```

```wat
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
```
