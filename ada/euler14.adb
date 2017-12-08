with Ada.Integer_Text_IO;
with Ada.Unchecked_Deallocation;

procedure Euler14 is
   Max_Start: constant Positive := 999_999;
   subtype Start_Type is Positive range 1 .. Max_Start;
   type Memo is array (Start_Type) of Natural;
   type Memo_Ptr is access Memo;
   procedure Free is new Ada.Unchecked_Deallocation(Memo, Memo_Ptr);

   Collatz: Memo_Ptr := new Memo'(1 => 1, others => 0);

   type Intermediate is range 1 .. 2 ** 60;
   function Chain_Length(Start: Intermediate) return Positive is
      Next: constant Intermediate
         := (if Start mod 2 = 0 then Start / 2 else 3 * Start + 1);
   begin
      if Start <= Intermediate(Start_Type'Last) then
         declare
            S: constant Start_Type := Start_Type(Start);
         begin
            if Collatz(S) = 0 then
               Collatz(S) := 1 + Chain_Length(Next);
            end if;
            return Collatz(S);
         end;
      else
         return 1 + Chain_Length(Next);
      end if;
   end Chain_Length;

   Max, Curr: Natural := 0;
   Best: Start_Type;
begin
   for I in Start_Type'Range loop
      Curr := Chain_Length(Intermediate(I));
      if Curr > Max then
         Max := Curr;
         Best := I;
      end if;
   end loop;
   Ada.Integer_Text_IO.Put(Best);
   Free(Collatz);
end Euler14;
