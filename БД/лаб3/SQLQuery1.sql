use master;
CREATE database Ber_MyBase;

use Ber_MyBase

create table ЗАКАЗЧИК
(	ID_заказчика int primary key not null,
	Дата_заказа date,
	Имя_заказчика nvarchar(50),
	Фамилия_заказчика nvarchar(50)
);

create table ПОСТАВЩИК
(	ID_поставщика int primary key not null,
	Название nvarchar(50),
	Адрес nvarchar(50),
	Телефон nvarchar(20)
) ON FG_Postavshchik;

create table СКЛАД
(	ID_детали int primary key not null,
	Артикул int,
	Цена real,
	Количество_деталей_на_складе int,
	Название_детали	nvarchar(50),
	Примечание nvarchar(50),
	ID_поставщика int foreign key references ПОСТАВЩИК (ID_поставщика)
) ON FG_Sклад;

create table ЗАКАЗ
(	ID_заказа int primary key not null,
	Количество_заказанных_деталей int,
	ID_заказчика int foreign key references ЗАКАЗЧИК (ID_заказчика),
	ID_детали int foreign key references СКЛАД (ID_детали)
) ON FG_Zakaz;

ALTER Table ЗАКАЗЧИК ADD POL nvarchar(1) default 'м' check (POL in ('м', 'ж'));
ALTER Table ЗАКАЗЧИК DROP Column POL;
insert into ЗАКАЗЧИК (ID_заказчика, Дата_заказа, Имя_заказчика, Фамилия_заказчика)
values (1, '2000-11-11', 'Vadim', 'Berezka'),
(2, '2012-12-12', 'Vlad', 'Shumskyi'),
(3, '2020-2-2', 'Semen', 'Pozin');

insert into ПОСТАВЩИК (ID_поставщика, Название, Адрес, Телефон)
values (11, 'БГТУ', 'Свердлова', '+375299780571'),
(22, 'БНТУ', 'Лупова', '+375299780572'),
(33, 'БГУ', 'Советская', '+375299780573');

insert into СКЛАД (ID_детали, Артикул, Цена, Количество_деталей_на_складе, Название_детали, Примечание, ID_поставщика)
values
(111, 123456, 25.50, 100, 'стул', 'крутой', 11),
(222, 654321, 15.75, 200, 'стол', 'еще круче', 22),
(333, 112233, 45.00, 50, 'пк', 'пк для учебы', 33);

insert into ЗАКАЗ (ID_заказа, Количество_заказанных_деталей, ID_заказчика, ID_детали)
values
(1111, 2, 1, 111),
(2222, 1, 2, 222),
(3333, 2, 1, 333);


SELECT * From СКЛАД; 
SELECT Дата_заказа From ЗАКАЗЧИК; 
SELECT count(*) From СКЛАД; 


UPDATE СКЛАД set Количество_деталей_на_складе = Количество_деталей_на_складе+5 Where Артикул = 123456;
SELECT Количество_деталей_на_складе From СКЛАД; 















USE master;
CREATE DATABASE Ber_MyBase
ON PRIMARY
(
    NAME = Ber_MyBase_Data,
    FILENAME = 'C:\University\БД\лаб3\Ber_MyBase_Data.mdf',
    SIZE = 10MB,
    MAXSIZE = 100MB,
    FILEGROWTH = 5MB
)
LOG ON
(
    NAME = Ber_MyBase_Log,
    FILENAME = 'C:\University\БД\лаб3\Ber_MyBase_Log.ldf',
    SIZE = 5MB,
    MAXSIZE = 25MB,
    FILEGROWTH = 1MB
);

ALTER DATABASE Ber_MyBase
ADD FILEGROUP FG_Sklad;
ALTER DATABASE Ber_MyBase
ADD FILEGROUP FG_Zakaz;
ALTER DATABASE Ber_MyBase
ADD FILEGROUP FG_Postavshchik;

ALTER DATABASE Ber_MyBase
ADD FILE
(
    NAME = Ber_MyBase_Sklad_Data,
    FILENAME = 'C:\University\БД\лаб3\Ber_MyBase_Sklad_Data.ndf',
    SIZE = 5MB,
    MAXSIZE = 50MB,
    FILEGROWTH = 5MB
) TO FILEGROUP FG_Sklad;

ALTER DATABASE Ber_MyBase
ADD FILE
(
    NAME = Ber_MyBase_Zakaz_Data,
    FILENAME = 'C:\University\БД\лаб3\Ber_MyBase_Zakaz_Data.ndf',
    SIZE = 5MB,
    MAXSIZE = 50MB,
    FILEGROWTH = 5MB
) TO FILEGROUP FG_Zakaz;

ALTER DATABASE Ber_MyBase
ADD FILE
(
    NAME = Ber_MyBase_Postavshchik_Data,
    FILENAME = 'C:\University\БД\лаб3\Ber_MyBase_Postavshchik_Data.ndf',
    SIZE = 5MB,
    MAXSIZE = 50MB,
    FILEGROWTH = 5MB
) TO FILEGROUP FG_Postavshchik;