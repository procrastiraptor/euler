with Ada.Containers.Generic_Array_Sort;
with Ada.Integer_Text_IO;
with Ada.Text_IO;
with Words;

procedure Euler22 is

   function Score(S: String) return Natural is
      Total: Natural := 0;
   begin
      for C of S loop
         Total := Total + Character'Pos(C) - Character'Pos('A') + 1;
      end loop;
      return Total;
   end Score;

   function "<"(L, R: Words.String_Ptr) return Boolean is (L.all < R.all);
   procedure Sort is new Ada.Containers.Generic_Array_Sort(
      Index_Type => Positive,
      Element_Type => Words.String_Ptr,
      Array_Type => Words.List);

begin
   declare
      Names: Words.List := Words.Split(Ada.Text_IO.Get_Line);
      Total: Natural := 0;
   begin
      Sort(Names);
      for I in Names'Range loop
         Total := Total + I * Score(Names(I).all);
      end loop;
      Ada.Integer_Text_IO.Put(Total);
      Words.Free(Names);
   end;
end Euler22;
