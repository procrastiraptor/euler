with Ada.Integer_Text_IO;

procedure Euler1 is
   Sum: Integer := 0;
begin
   for I in Integer range 1 .. 999 loop
      if I mod 3 = 0 or I mod 5 = 0 then
         Sum := Sum + I;
      end if;
   end loop;
   Ada.Integer_Text_IO.Put(Sum);
end Euler1;
