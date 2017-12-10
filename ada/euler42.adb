with Ada.Integer_Text_IO;
with Ada.Text_IO;
with Words;

procedure Euler42 is

   function Is_Triangular(I: Integer) return Boolean is
      T: Integer := 1;
      N: Integer := 2;
   begin
      while T <= I loop
         if T = I then return True; end if;
         T := T + N;
         N := N + 1;
      end loop;
      return False;
   end Is_Triangular;

begin
   declare
      List: Words.List := Words.Split(Ada.Text_IO.Get_Line);
      Count: Natural := 0;
   begin
      for W of List loop
         if Is_Triangular(Words.Score(W.all)) then
            Count := Count + 1;
         end if;
      end loop;
      Words.Free(List);
      Ada.Integer_Text_IO.Put(Count);
   end;
end Euler42;
