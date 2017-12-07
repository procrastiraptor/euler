function Is_Palindrome(S: Seq) return Boolean is
   J: Index := S'Last;
begin
   for I in S'Range loop
      if S(I) /= S(J) then return False; end if;
      exit when I = S'Last;
      J := Index'Pred(J);
   end loop;
   return True;
end Is_Palindrome;
