package body String_Int is
   Zero_Pos: constant Natural := Digit'Pos(Digit'First); 

   procedure Add(A, B: in Digit; Sum: out Digit; Carry: in out Digit) is
      S: Natural := Digit'Pos(A) + Digit'Pos(B) + Digit'Pos(Carry);
   begin
      S := S - 3 * Zero_Pos;
      Sum := Digit'Val((S mod 10) + Zero_Pos);
      Carry := Digit'Val(S / 10 + Zero_Pos);
   end Add;

   function "+"(A, B: Number) return Number is
      Result: Number(1 .. 1 + Index'Max(A'Length, B'Length));
      Carry: Digit := '0';
      AI: Integer := A'Last;
      BI: Integer := B'Last;
   begin
      for Dst in reverse Result'Range loop
         Add(
            A => (if AI < A'First then '0' else A(AI)),
            B => (if BI < B'First then '0' else B(BI)),
            Sum => Result(Dst),
            Carry => Carry);
         AI := Integer'Pred(AI);
         BI := Integer'Pred(BI);
      end loop;
      for I in Result'Range loop
         if Result(I) /= '0' then
            return Result(I .. Result'Last);
         end if;
      end loop;
      return Result;
   end "+";

   function From_String(S: String) return Number is
      Result: Number(S'Range);
   begin
      for I in S'Range loop Result(I) := Digit(S(I)); end loop;
      return Result;
   end From_String;

   function To_String(N: Number) return String is
      Result: String(N'Range);
   begin
      for I in N'Range loop Result(I) := Character(N(I)); end loop;
      return Result;
   end To_String;

end String_Int;
