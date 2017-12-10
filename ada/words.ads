package Words is
   type String_Ptr is access String;
   type List is array (Positive range <>) of String_Ptr;

   function Split(S: String; On: Character := ',') return List;
   procedure Free(L: in out List);
end Words;
