module StringMap = Map.Make(String);

type builtinFunction =
  | Equals
  | Plus
  | Minus
  | Times
  | First
  | Println;

type expression =
  | True
  | False
  | Number(int)
  | Symbol(string)
  | List(list(expression))
  | Function(builtinFunction)
  | Lambda(environment, list(string), expression)

and environment = StringMap.t(expression);

type readResult =
  | EndOfTokens(list(expression))
  | EndOfExpression(list(expression), list(string));

exception ArgumentError(string);

exception UnbalancedParens;

type frame =
  | Start(environment, expression)
  | AddToEnv(environment, string)
  | PushBranch(environment, expression, expression)
  | EvalFn(environment, list(expression))
  | EvalArgs(environment, expression, list(expression), list(expression))
  | Stop(environment, expression);

type stack = list(frame);
