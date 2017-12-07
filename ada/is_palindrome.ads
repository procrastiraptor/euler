generic
   type Element is private;
   type Index is (<>);
   type Seq is array (Index range <>) of Element;
function Is_Palindrome(S: Seq) return Boolean;
