create procedure Insert_Bil_in (
@ID_Bill int,

@Name_Sup nvarchar(30),  -- Supplier
@Address_Sup nvarchar(60),
@Phone_Number nvarchar(20),

@Email_Sup char(60),
@Date_Phieu date
)
as 
BEGIN
 Declare @ID_Sup int

 --Supplier
 if (@Name_Sup is not null)
 BEGIN
  select @ID_Sup = ID_Sup from Supplier where Name_Sup = @Name_Sup
  if ( @ID_Sup is null ) 
  BEGIN
   Insert into Supplier 
   values (@Name_Sup,@Address_Sup,@Phone_Number,@Email_Sup)
   select @ID_Sup = SCOPE_IDENTITY()
  END
 END

  Insert into Bill 
  values (@ID_Bill,NULL,@ID_Sup,@Date_Phieu,1);
 --END
END

/*
use Sneaker_Storage
drop procedure Insert_Bill_in
*/