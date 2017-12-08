with Ada.Text_IO;

procedure Euler8 is

   Product_Size : constant Positive := 13;
   type Product is range 0 .. 9 ** Product_Size;
   package Product_IO is new Ada.Text_IO.Integer_IO(Product);

   function String_Product(S: String) return Product is
      Prod: Product := 1;
   begin
      for C of S loop
         Prod := Prod * (Character'Pos(C) - Character'Pos('0'));
      end loop;
      return Prod;
   end String_Product;

   Line_Length: constant Positive := 50;
   Number: String(1 .. 1000);
   Append: Positive := Number'First;

   Curr, Max: Product := 0;
begin
   while not Ada.Text_IO.End_Of_File loop
      Number(Append .. Append + Line_Length - 1) := Ada.Text_IO.Get_Line;
      Append := Append + Line_Length;
   end loop;
   for I in Number'Range loop
      exit when I + Product_Size - 1 > Number'Last;
      Curr := String_Product(Number(I .. I + Product_Size - 1));
      if Curr > Max then Max := Curr; end if;
   end loop;
   Product_IO.Put(Max);
end Euler8;
