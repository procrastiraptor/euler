with Ada.Containers.Generic_Array_Sort;
with Ada.Integer_Text_IO;
with Ada.Text_IO;
with Words;

procedure Euler22 is

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
         Total := Total + I * Words.Score(Names(I).all);
      end loop;
      Ada.Integer_Text_IO.Put(Total);
      Words.Free(Names);
   end;
end Euler22;
