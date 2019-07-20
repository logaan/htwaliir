open CoreTypes;
open PrettyPrint;
open StringMap;

let builtinApply = (func, args) =>
  switch (func, args) {
  | (Plus, [Number(a), Number(b)]) => Number(a + b)
  | (Minus, [Number(a), Number(b)]) => Number(a - b)
  | (Times, [Number(a), Number(b)]) => Number(a * b)
  | (First, [List([first, ..._rest])]) => first
  | (Println, [value]) =>
    value |> string_of_expression |> print_endline;
    value;
  | _ => raise(ArgumentError("ArgumentError on a builtin function."))
  };

let environment =
  StringMap.empty
  |> add("+", Function(Plus))
  |> add("-", Function(Minus))
  |> add("*", Function(Times))
  |> add("first", Function(First))
  |> add("println", Function(Println));
