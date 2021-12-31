CREATE PROCEDURE Insert_Data (
	@ID_Bill int,
    @Brand_Sneaker nvarchar(30), -- Sneaker
    @Model_Sneaker nvarchar(30),
    @Name_Sneaker nvarchar(60),
    @Collaboration bit,
    @Name_Collaboration nvarchar(30),
    @users nvarchar(30),
    @Colors_Sneaker nvarchar(30),
    @Luxury bit,
    @size float ,
    @amount int  ,
    @Price_in float 
    --,@Price_out float
	)
AS
BEGIN
    --Khai bao bien

    Declare @ID_Sneaker int
	Declare @SizeS int
	Declare @idb int
    
    --Sneaker
    select @ID_Sneaker =ID_Sneaker from Sneaker where Brand_Sneaker = @Brand_Sneaker and Model_Sneaker = @Model_Sneaker and Name_Sneaker = @Name_Sneaker
    if ( @ID_Sneaker is null ) 
    BEGIN
     Insert into Sneaker 
     values (@Brand_Sneaker,@Model_Sneaker,@Name_Sneaker,@Collaboration,@Name_Collaboration,@users,@Colors_Sneaker,@Luxury)
     select @ID_Sneaker = SCOPE_IDENTITY()
    END

    --Infor Sneaker
    select @SizeS = Size from Infor_Sneaker where ID_Sneaker = @ID_Sneaker and size = @size;
    if ( @SizeS is null )
    BEGIN
     Insert into Infor_Sneaker(ID_Sneaker,Size,Amount)
     values (@ID_Sneaker,@size,@amount);
     --select @ID_Infor_Sneaker = SCOPE_IDENTITY()
    END
    ELSE 
    BEGIN
     UPDATE Infor_Sneaker
     SET Amount += @amount Where ID_Sneaker = @ID_Sneaker and size = @size;
	 /*UPDATE Size_Sneaker
	 SET Price = @Price_out*/
    END

	-- Infor Bill
	select @idb =@ID_Bill from Infor_Bill where ID_Bill =@ID_Bill and ID_Sneaker = @ID_Sneaker and Size =@size
    if ( @idb is null )
	begin
     Insert into Infor_Bill(ID_Bill,ID_Sneaker,Size,amount,Price_in)
     values (@ID_Bill,@ID_Sneaker,@size,@amount,@Price_in)
	end
END

--use Sneaker_Storage
--drop procedure Insert_Data