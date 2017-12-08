with Ada.Integer_Text_IO;

procedure Euler9 is

   function Pythagorean(A, B, C: Positive) return Boolean is
      (A * A + B * B = C * C);

   C: Positive;
begin
   for A in Positive range 1 .. 998 loop
      for B in Positive range A .. 1000 - A - 1 loop
         C := 1000 - A - B;
         if Pythagorean(A, B, C) then
            Ada.Integer_Text_IO.Put(A * B * C);
            return;
         end if;
      end loop;
   end loop;
end Euler9;
