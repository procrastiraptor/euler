with Ada.Integer_Text_IO;

procedure Euler5 is
   function Divisible(I: Positive) return Boolean is
      (for all D in Positive range 3 .. 20 => I mod D = 0);

   I: Positive := 20;
begin
   while not Divisible(I) loop I := I + 20; end loop;
   Ada.Integer_Text_IO.Put(I);
end Euler5;
