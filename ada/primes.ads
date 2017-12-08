package Primes is

   type List is array (Positive range <>) of Positive;

   function First(N: Positive) return List;
end Primes;
