with Ada.Integer_Text_IO;

procedure Euler2 is
   A, B: Integer := 1;
   Sum : Integer := 0;
   Tmp: Integer;
begin
   while A < 4_000_000 loop
      if A mod 2 = 0 then Sum := Sum + A; end if;
      Tmp := A;
      A := A + B;
      B := Tmp;
   end loop;
   Ada.Integer_Text_IO.Put(Sum);
end Euler2;
