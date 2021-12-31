use Sneaker_Storage

----              Phieu 1

declare @d1 date = '2020-10-31'
execute Insert_Bil_in 1,'Chuong Thai','Quang Nam, VietNam','0345608954','chuongthai885@gmail.com',@d1

Execute Insert_Data 1,
'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
9.5,15,'320'
update Infor_Sneaker
set Price_out = '375' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 9.5

--              PHIEU 2

declare @d3 date = '2020-11-1'
execute Insert_Bil_in 2,'Hung  Dinh','New York, USA','018293412','hungdinh152@gmail.com',@d3 

Execute Insert_Data 2,
'Adidas','Yeezy 350','Yeezy Boost 350 V2 Zebra',0,null,'Casual Shoes','Black,White',0,
6,19,'300'

update Infor_Sneaker
set Price_out = '351' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 350 V2 Zebra')
and Size = 6

Execute Insert_Data 2,
'Adidas','Yeezy 350','Yeezy Boost 350 V2 Zebra',0,null,'Casual Shoes','Black,White',0,
6.5,12,'289'

update Infor_Sneaker
set Price_out = '354' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 350 V2 Zebra')
and Size = 6.5

Execute Insert_Data 2,
'Adidas','Yeezy 350','Yeezy Boost 350 V2 Zebra',0,null,'Casual Shoes','Black,White',0,
9.5,14,'290'

update Infor_Sneaker
set Price_out = '327' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 350 V2 Zebra')
and Size = 9.5

Execute Insert_Data 2,
'Adidas','Yeezy 350','Yeezy Boost 350 V2 Zebra',0,null,'Casual Shoes','Black,White',0,
9.5,14,'290'

update Infor_Sneaker
set Price_out = '327' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 350 V2 Zebra')
and Size = 9.5

Execute Insert_Data 2,
'Adidas','Yeezy 350','Yeezy Boost 350 V2 Zebra',0,null,'Casual Shoes','Black,White',0,
17,2,'307'

update Infor_Sneaker
set Price_out = '360' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 350 V2 Zebra')
and Size = 17


--                 PHIEU 3
declare @d4 date = '2020-11-15'

execute Insert_Bil_in 3,'Nguyen Luu','Da Nang,Viet Nam','0964611771',null,@d4

--1
execute Insert_Data 3,
'Adidas','Yeezy 350','Yeezy Boost 350 V2 Black Red',0,null,'Casual Shoes','Black,Red',0,
6,7,'387'

update Infor_Sneaker
set Price_out = '416' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 350 V2 Black Red')
and Size = 6

execute Insert_Data 3,
'Adidas','Yeezy 350','Yeezy Boost 350 V2 Black Red',0,null,'Casual Shoes','Black,Red',0,
12,3,'300'

update Infor_Sneaker
set Price_out = '376' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 350 V2 Black Red')
and Size = 12

--2

execute Insert_Data 3,
'Adidas','Yeezy 350','Yeezy Boost 350 V2 core Black Red',0,null,'Casual Shoes','Black,Red',0,
5,1,'2965'

update Infor_Sneaker
set Price_out = '3193' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 350 V2 core Black Red')
and Size = 5

execute Insert_Data 3,
'Adidas','Yeezy 350','Yeezy Boost 350 V2 core Black Red',0,null,'Casual Shoes','Black,Red',0,
9.5,2,'1290'

update Infor_Sneaker
set Price_out = '1350' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 350 V2 core Black Red')
and Size = 9.5


--                 PHIEU 4
declare @d5 date = '2020-11-29'

execute Insert_Bil_in 4,'Nguyen Thi Thanh Lam','Tokyo,Japan','029467193',null,@d5
--1
execute Insert_Data 4,
'Adidas','Yeezy 700','Yeezy 700 V2 Static',0,null,'Casual Shoes','Grey,White,Black',0,
9,4,'700'

update Infor_Sneaker
set Price_out = '795' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy 700 V2 Static')
and Size = 9

execute Insert_Data 4,
'Adidas','Yeezy 700','Yeezy 700 V2 Static',0,null,'Casual Shoes','Grey,White,Black',0,
9.5,8,'685'

update Infor_Sneaker
set Price_out = '748' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy 700 V2 Static')
and Size = 9.5

--2
execute Insert_Data 4,
'Jordan','Jordan 3','Jordan 3 Retro Laser Orange(PS)',0,null,'Casual Shoes','Grey,White,Laser Orange',0,
12.5,2,'80'

update Infor_Sneaker
set Price_out = '100' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 3 Retro Laser Orange(PS)')
and Size = 12.5

--3

execute Insert_Data 4,
'Adidas','Yeezy 700','Yeezy Boost 700 V3 Azael',0,null,'Casual Shoes','Cream,White,Black,Sky Blue',0,
8.5,5,'720'

update Infor_Sneaker
set Price_out = '799' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 700 V3 Azael')
and Size = 8.5

execute Insert_Data 4,
'Adidas','Yeezy 700','Yeezy Boost 700 V3 Azael',0,null,'Casual Shoes','Cream,White,Black,Sky Blue',0,
9,5,'700'

update Infor_Sneaker
set Price_out = '770' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 700 V3 Azael')
and Size = 9

execute Insert_Data 4,
'Adidas','Yeezy 700','Yeezy Boost 700 V3 Azael',0,null,'Casual Shoes','Cream,White,Black,Sky Blue',0,
9.5,5,'700'

update Infor_Sneaker
set Price_out = '772' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 700 V3 Azael')
and Size = 9.5


--                 PHIEU 5
declare @d6 date = '2020-12-16'

execute Insert_Bil_in 5,'Nguyen Tan Thang','TP Ho Chi Minh, Viet Nam','0837263927',null,@d6
--1

execute Insert_Data 5,
'Jordan','Jordan 4','Jordan 4 Retro OFF-WHITE Sail',1,'OFF-WHITE','Casual Shoes','Cream,White',0,
6.5,3,'1000'

update Infor_Sneaker
set Price_out = '1100' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 4 Retro OFF-WHITE Sail')
and Size = 6.5

execute Insert_Data 5,
'Jordan','Jordan 4','Jordan 4 Retro OFF-WHITE Sail',1,'OFF-WHITE','Casual Shoes','Cream,White',0,
9.5,1,'998'

update Infor_Sneaker
set Price_out = '1050' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 4 Retro OFF-WHITE Sail')
and Size = 9.5

--2
execute Insert_Data 5,
'Jordan','Jordan 5','Jordan 5 Retro OFF-WHITE Black',1,'OFF-WHITE','Casual Shoes','Black,Dark Grey,Salmon',0,
7,3,'640'

update Infor_Sneaker
set Price_out = '700' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 5 Retro OFF-WHITE Black')
and Size = 7
--3
execute Insert_Data 5,
'Adidas','Yeezy 700','Yeezy Boost 700 V2 Tephra',0,null,'Casual Shoes','Tephra color',0,
6,2,'600'

update Infor_Sneaker
set Price_out = '636' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 700 V2 Tephra')
and Size = 6

execute Insert_Data 5,
'Adidas','Yeezy 700','Yeezy Boost 700 V2 Tephra',0,null,'Casual Shoes','Tephra color',0,
6.5,2,'600'

update Infor_Sneaker
set Price_out = '675' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 700 V2 Tephra')
and Size = 6.5

execute Insert_Data 5,
'Adidas','Yeezy 700','Yeezy Boost 700 V2 Tephra',0,null,'Casual Shoes','Tephra color',0,
10,4,'349'

update Infor_Sneaker
set Price_out = '389' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 700 V2 Tephra')
and Size = 10

execute Insert_Data 5,
'Adidas','Yeezy 700','Yeezy Boost 700 V2 Tephra',0,null,'Casual Shoes','Tephra color',0,
11,1,'340'

update Infor_Sneaker
set Price_out = '388' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Yeezy Boost 700 V2 Tephra')
and Size = 11


--                 PHIEU 6

declare @d date = '2020-12-20'
execute Insert_Bil_in 6,'Fabo Nguyen','Sai Gon, Viet Nam',Null,'abac@gmail.com',@d
--1

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
8,15,'350'

update Infor_Sneaker
set Price_out = '404' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 8

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
8.5,3,'370'

update Infor_Sneaker
set Price_out = '417' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 8.5

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
9,5,'365'

update Infor_Sneaker
set Price_out = '410' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 9

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
9.5,2,'400'

update Infor_Sneaker
set Price_out = '419' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 9.5

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
10,6,'350'

update Infor_Sneaker
set Price_out = '395' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 10

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
10.5,6,'390'

update Infor_Sneaker
set Price_out = '400' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 10.5

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
11,6,'395'

update Infor_Sneaker
set Price_out = '409' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 11

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
11.5,1,'400'

update Infor_Sneaker
set Price_out = '425' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 11.5

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
12,5,'350'

update Infor_Sneaker
set Price_out = '400' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 12

--2

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High OFF-WHITE Chicago',1,'OFF-WHITE','Casual Shoes','Red,White',0,
8,2,'4700'

update Infor_Sneaker
set Price_out = '4799' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High OFF-WHITE Chicago')
and Size = 8

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High OFF-WHITE Chicago',1,'OFF-WHITE','Casual Shoes','Red,White',0,
8.5,2,'6599'

update Infor_Sneaker
set Price_out = '6642' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High OFF-WHITE Chicago')
and Size = 8.5

Execute Insert_Data 6,'Jordan','Jordan 1','Jordan 1 Retro High OFF-WHITE Chicago',1,'OFF-WHITE','Casual Shoes','Red,White',0,
9.5,5,'4955'

update Infor_Sneaker
set Price_out = '5100' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High OFF-WHITE Chicago')
and Size = 9.5


--             Phieu 7
declare @d2 date = getdate()
execute Insert_Bil_in 7,'Vo Kim','Florida , USA','1224657392',NULL,@d2

--1
Execute Insert_Data 7,
'Balenciaga','Balenciaga Triple S','Balenciaga Triple S Allover Logo Black',0,null,'Fashion Sneakers','Black,White',1,
40,2,'999'
update Infor_Sneaker
set Price_out = '1057' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Balenciaga Triple S Allover Logo Black')
and Size = 40

Execute Insert_Data 7,
'Balenciaga','Balenciaga Triple S','Balenciaga Triple S Allover Logo Black',0,null,'Fashion Sneakers','Black,White',1,
42,7,'754'
update Infor_Sneaker
set Price_out = '827' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Balenciaga Triple S Allover Logo Black')
and Size = 42

Execute Insert_Data 7,
'Balenciaga','Balenciaga Triple S','Balenciaga Triple S Allover Logo Black',0,null,'Fashion Sneakers','Black,White',1,
43,7,'752'
update Infor_Sneaker
set Price_out = '832' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Balenciaga Triple S Allover Logo Black')
and Size = 43

--2

Execute Insert_Data 7,
'Balenciaga','Balenciaga Track Trainers','Balenciaga Track Trainers Burgundy Black',0,null,'Fashion Sneakers','Black,White',1,
39,3,'496'

update Infor_Sneaker
set Price_out = '594' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Balenciaga Track Trainers Burgundy Black')
and Size = 39

Execute Insert_Data 7,
'Balenciaga','Balenciaga Track Trainers','Balenciaga Track Trainers Burgundy Black',0,null,'Fashion Sneakers','Black,White',1,
44,2,'583'

update Infor_Sneaker
set Price_out = '680' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Balenciaga Track Trainers Burgundy Black')
and Size = 44

-- PHIEU 8
execute Insert_Bill_out 8,'Phuc Nguyen','Da Nang ,Viet Nam',null,null
execute update_data 8,1,9.5,5

--PHIEU 9

declare @dn date = getdate();
execute Insert_Bil_in 9,'Chuong Thai','Quang Nam, VietNam','0345608954','chuongthai885@gmail.com',@dn

Execute Insert_Data 9,
'Jordan','Jordan 1','Jordan 1 Retro High Dark Mocha',0,NULL,'Casual Shoes','Black,Dark Mocha,White',0,
6,9,'400'
update Infor_Sneaker
set Price_out = '455' where ID_Sneaker = (select ID_Sneaker from Sneaker where Name_Sneaker = 'Jordan 1 Retro High Dark Mocha')
and Size = 6