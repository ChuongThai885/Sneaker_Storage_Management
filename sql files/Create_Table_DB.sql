use Sneaker_Storage

create table Supplier(
    ID_Sup int primary key identity(1,1) not null,
    Name_Sup nvarchar(30),
    Address_Sup nvarchar(60),
    Phone_Number nvarchar(20),
    Email_Sup char(60),
)   

create table Customer(
    ID_Customer int primary key identity(1,1) not null, 
    Name_Customer nvarchar(30),
    Address_Customer nvarchar(60),
    Phone_Number nvarchar(20),
    Email_Customer nvarchar(60),
)

create table Sneaker(
    ID_Sneaker int primary key identity(1,1) not null,
    Brand_Sneaker nvarchar(30) not null,
    Model_Sneaker nvarchar(30) not null,
    Name_Sneaker nvarchar(60) ,
    Collaboration bit not null ,
    Name_Collaboration nvarchar(30),
    users nvarchar(30) not null,
    Colors_Sneaker nvarchar(30) not null,
    Luxury bit not null,
    CONSTRAINT Unique_Name_Sneaker UNIQUE (Brand_Sneaker,Model_Sneaker,Name_Sneaker),
)

create table Infor_Sneaker(
    ID_Sneaker int not null,
    Size float check(size >=0) not null,
    Amount int check(amount >=0) not null default(0), -- tổng số lượng/sz 
	Price_out float check(price_out > 0),
	--create foreign key ID_Sneaker
	CONSTRAINT fk_ID_Sneaker
        FOREIGN KEY(ID_Sneaker)
        REFERENCES Sneaker(ID_Sneaker),
	--create primarykey for this table
	CONSTRAINT pk_ID_Sz
	PRIMARY KEY CLUSTERED (ID_Sneaker,Size),
)


create table Bill(
    ID_Bill int primary key  not null,
	ID_Customer int,
	ID_Sup int,
    Date_Phieu date not null,
    Phieu_Nhap bit not null,
	-- create foreign key
	CONSTRAINT fk_cus_ID
        FOREIGN KEY(ID_Customer)
        REFERENCES Customer(ID_Customer),
	CONSTRAINT fk_sup_ID
        FOREIGN KEY(ID_Sup)
        REFERENCES Supplier(ID_Sup),
)

create table Infor_Bill(
    ID_Bill int not null,
    ID_Sneaker int not null,
    Size float Check(size > 0) not null,
    amount int check(amount >= 0) default(0),
    Price_in float check(price_in > 0) ,
	Price_out float check(price_out > 0) ,
    --create foreign key
	CONSTRAINT fk_Bill_ID
        FOREIGN KEY(ID_Bill)
        REFERENCES Bill(ID_Bill),
	CONSTRAINT fk_Sneaker_Size
	    FOREIGN KEY (ID_Sneaker,Size)
		REFERENCES Infor_Sneaker(ID_Sneaker,Size),
	
	--create primary key
    CONSTRAINT pk_SneakerSize_Bill
	    primary key clustered (ID_Bill,ID_Sneaker,Size),
)

/*drop table Infor_Bill;
drop table Bill;
drop table Supplier;
drop table Customer;
drop table Infor_Sneaker;
drop table Sneaker;*/



/*select * from Infor_Bill; --test insert
select * from Supplier;
--select * from Customer;
select * from Bill;
select * from Infor_Sneaker;
select * from Sneaker;*/



/*delete Infor_Phieu
delete Supplier
delete Customer
delete Phieu
delete Size_Sneaker
delete Sneaker*/


