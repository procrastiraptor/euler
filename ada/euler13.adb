with Ada.Text_IO;
with String_Int;

procedure Euler13 is
   Num_Addends: constant Positive := 100;
   Addend_Size: constant Positive := 50;

   use type String_Int.Number;
   Result: String_Int.Number(1 .. Addend_Size + Num_Addends) := (others => '0');
   Len: Positive := Addend_Size;
begin
   for I in Positive range 1 .. Num_Addends loop
      declare
         Sum: constant String_Int.Number
            := Result(1 .. Len) + String_Int.From_String(Ada.Text_IO.Get_Line);
      begin
         Len := Sum'Length;
         Result(1 .. Len) := Sum;
      end;
   end loop;
   Ada.Text_IO.Put_Line(String_Int.To_String(Result(1 .. 10)));
end Euler13;
