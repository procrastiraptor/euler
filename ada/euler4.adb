with Ada.Integer_Text_IO;

with Is_Palindrome;

procedure Euler4 is
   function String_Palindrome is new Is_Palindrome(Character, Positive, String);
   Prod, Max: Integer := 0;
begin
   for I in Integer range 100 .. 999 loop
      for J in Integer range I .. 999 loop
         Prod := I * J;
         if Prod > Max and String_Palindrome(Integer'Image(Prod) & ' ') then
            Max := Prod;
         end if;
      end loop;
   end loop;
   Ada.Integer_Text_IO.Put(Max);
end Euler4;
