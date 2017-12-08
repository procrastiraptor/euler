with Ada.Integer_Text_IO;

procedure Euler6 is
   Sum_Of_Squares, Sum_Of_Ints: Integer := 0;
begin
   for I in Integer range 1 .. 100 loop
      Sum_Of_Squares := Sum_Of_Squares + I * I;
      Sum_Of_Ints := Sum_Of_Ints + I;
   end loop;
   Ada.Integer_Text_IO.Put(Sum_Of_Ints * Sum_Of_Ints - Sum_Of_Squares);
end Euler6;
