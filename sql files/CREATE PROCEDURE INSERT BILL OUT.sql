create procedure Insert_Bill_out(
@ID_Bill int,

@Name_Cus nvarchar(30),  -- Customer
@Address_Cus nvarchar(60),
@Phone_Number nvarchar(20),

@Email_Cus char(60)
)
AS 
BEGIN
   DECLARE @ID_Cus int
   DECLARE @Date date = getdate();

   --Customer
   if (@Name_Cus is not null)
   BEGIN
      select @ID_Cus = ID_Customer from Customer where Name_Customer = @Name_Cus
      if ( @ID_Cus is null ) 
      BEGIN
         Insert into Customer 
         values (@Name_Cus,@Address_Cus,@Phone_Number,@Email_Cus)
         select @ID_Cus = SCOPE_IDENTITY()
      END
   END

   --Bill
   Insert into Bill 
   values (@ID_Bill,@ID_Cus,NULL,@Date,0);
END
--use Sneaker_Storage
--Drop procedure Insert_Bill_out