with Ada.Unchecked_Deallocation;

package body Words is
   function Split(S: String; On: Character := ',') return List is
      Count: Natural := 0;
   begin
      for C of S loop
         if C = On then Count := Count + 1; end if;
      end loop;
      declare
         Result: List(1 .. Count + 1);
         From, To: Positive := Result'First;
      begin
         for I in Result'Range loop
            To := From + 1;
            while S(To) /= '"' loop To := To + 1; end loop;
            Result(I) := new String'(S(From + 1 .. To - 1));
            From := To + 2;
         end loop;
         return Result;
      end;
   end Split;

   procedure Free_Word is new Ada.Unchecked_Deallocation(String, String_Ptr);
   procedure Free(L: in out List) is
   begin
      for W of L loop Free_Word(W); end loop;
   end Free;
end Words;
