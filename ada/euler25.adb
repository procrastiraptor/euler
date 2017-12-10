with Ada.Integer_Text_IO;
with String_Int;

procedure Euler25 is
   Max_Digits: constant Positive := 1000;

   use type String_Int.Number;
   A, B: String_Int.Number(1 .. Max_Digits)
         := (Max_Digits => '1', others => '0');
   Term: Positive := 3;
begin
   loop
      declare
         Sum: constant String_Int.Number := A + B;
         First: constant Natural := A'Last - Sum'Length + 1;
      begin
         if Sum'Length = Max_Digits then
            Ada.Integer_Text_IO.Put(Term);
            return;
         end if;
         Term := Term + 1;
         B := A;
         A(First .. A'Last) := Sum;
      end;
   end loop;
end Euler25;
