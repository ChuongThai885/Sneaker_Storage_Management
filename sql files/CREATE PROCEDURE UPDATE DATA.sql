CREATE PROCEDURE update_data(
 @ID_Bill int,
 @ID_S int,
 @sz float,
 @amount int
)
AS 
BEGIN
   Declare @a int;
   Declare @p float;

   --Infor Sneaker
   select @a = Amount from Infor_Sneaker where ID_Sneaker = @ID_S and Size = @sz
   update Infor_Sneaker
   set Amount = @a - @amount where ID_Sneaker = @ID_S and Size = @sz

   --Infor Bill
   select @p = Price_out from Infor_Sneaker where ID_Sneaker = @ID_S and Size = @sz
   INSERT INTO Infor_Bill
   values (@ID_Bill,@ID_S,@sz,@amount,null,@p);

END
/*
use Sneaker_Storage
drop procedure update_data
*/