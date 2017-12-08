with Ada.Integer_Text_IO;
with Ada.Text_IO;
with Ada.Unchecked_Deallocation;

procedure Euler18 is

   type Node is
      record
         Value: Natural := 0;
         Max_Path: Integer := -1;
         Left, Right: access Node := null;
      end record;

   function Max_Path(N: in out Node) return Natural is
      L, R: Natural := 0;
   begin
      if N.Max_Path >= 0 then return Natural(N.Max_Path); end if;
      if N.Left /= null then L := Max_Path(N.Left.all); end if;
      if N.Right /= null then R := Max_Path(N.Right.all); end if;
      N.Max_Path := Integer(N.Value + Natural'Max(L, R));
      return Natural(N.Max_Path);
   end Max_Path;

   type Node_Row is array (Positive range <>) of aliased Node;
   type Row(Length: Positive) is
      record
         Next: access Row;
         Nodes: Node_Row(1 .. Length);
      end record;
   type Row_Ptr is access all Row;
   procedure Free_Row is new Ada.Unchecked_Deallocation(Row, Row_Ptr);

   procedure Free(R: in out Row_Ptr) is
   begin
      if R.Next /= null then Free(R.Next); end if;
      Free_Row(R);
   end Free;

   Root: aliased Row(1);
   Current_Row: Row_Ptr := Root'Access;
   Index: Positive := Root.Nodes'First;
   Value: Natural;
begin
   while not Ada.Text_IO.End_Of_File loop
      if Index > Current_Row.Nodes'Last then
         Current_Row.Next := 
            new Row'(Length => Index, Next => null, Nodes => <>);
         Current_Row := Current_Row.Next;
         Index := Current_Row.Nodes'First;
      end if;
      Ada.Integer_Text_IO.Get(Value);
      Current_Row.Nodes(Index).Value := Value;
      Index := Index + 1;
   end loop;

   Current_Row := Root'Access;
   while Current_Row.Next /= null loop
      for I in Current_Row.Nodes'Range loop
         Current_Row.Nodes(I).Left := Current_Row.Next.Nodes(I)'Access;
         Current_Row.Nodes(I).Right := Current_Row.Next.Nodes(I + 1)'Access;
      end loop;
      Current_Row := Current_Row.Next;
   end loop;

   Ada.Integer_Text_IO.Put(Max_Path(Root.Nodes(1)));
   Free(Root.Next);
end Euler18;
