with Ada.Containers.Generic_Array_Sort;
with Ada.Integer_Text_IO;
with Ada.Text_IO;
with Ada.Unchecked_Deallocation;

procedure Euler22 is

   function Score(S: String) return Natural is
      Total: Natural := 0;
   begin
      for C of S loop
         Total := Total + Character'Pos(C) - Character'Pos('A') + 1;
      end loop;
      return Total;
   end Score;

   type String_Ptr is access String;
   procedure Free is new Ada.Unchecked_Deallocation(String, String_Ptr);
   type Name_List is array (Positive range <>) of String_Ptr;

   function "<"(L, R: String_Ptr) return Boolean is (L.all < R.all);
   procedure Sort is new Ada.Containers.Generic_Array_Sort(
      Index_Type => Positive,
      Element_Type => String_Ptr,
      Array_Type => Name_List);

   function To_Names(S: String) return Name_List is
      Commas: Natural := 0;
   begin
      for C of S loop
         if C = ',' then Commas := Commas + 1; end if;
      end loop;
      declare
         List: Name_List(1 .. Commas + 1);
         X, Y: Positive := S'First;
      begin
         for I in List'Range loop
            Y := X + 1;
            while S(Y) /= '"' loop Y := Y + 1; end loop;
            List(I) := new String'(S(X + 1 .. Y - 1));
            X := Y + 2;
         end loop;
         return List;
      end;
   end To_Names;

begin
   declare
      Names: Name_List := To_Names(Ada.Text_IO.Get_Line);
      Total: Natural := 0;
   begin
      Sort(Names);
      for I in Names'Range loop
         Total := Total + I * Score(Names(I).all);
         Free(Names(I));
      end loop;
      Ada.Integer_Text_IO.Put(Total);
   end;
end Euler22;
