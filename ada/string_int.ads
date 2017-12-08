package String_Int is

   type Digit is new Character range '0' .. '9';
   subtype Index is Positive;
   type Number is array (Index range <>) of Digit;

   function From_String(S: String) return Number;
   function To_String(N: Number) return String;
   function "+"(A, B: Number) return Number;

end String_Int;
