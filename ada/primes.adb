package body Primes is

   function Next(Ps: List) return Positive is
   begin
      case Ps'Length is
         when 0 => return 2;
         when 1 => return 3;
         when others =>
            declare
               N: Positive := Ps(Ps'Last) + 2;
            begin
               while (for some P of Ps => N mod P = 0) loop
                  N := N + 2;
               end loop;
               return N;
            end;
      end case;
   end Next;

   function First(N: Positive) return List is
      Result: List(1 .. N) := (others => 1);
   begin
      for I in Result'Range loop
         Result(I) := Next(Result(Result'First .. I - 1));
      end loop;
      return Result;
   end First;
end Primes;
