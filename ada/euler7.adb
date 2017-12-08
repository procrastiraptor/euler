with Ada.Integer_Text_IO;
with Primes;

procedure Euler7 is
   Ps: constant Primes.List := Primes.First(10_001);
begin
   Ada.Integer_Text_IO.Put(Ps(Ps'Last));
end Euler7;
