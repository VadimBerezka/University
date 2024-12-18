use master;
CREATE database Ber_MyBase;

use Ber_MyBase

create table ��������
(	ID_��������� int primary key not null,
	����_������ date,
	���_��������� nvarchar(50),
	�������_��������� nvarchar(50)
);

create table ���������
(	ID_���������� int primary key not null,
	�������� nvarchar(50),
	����� nvarchar(50),
	������� nvarchar(20)
) ON FG_Postavshchik;

create table �����
(	ID_������ int primary key not null,
	������� int,
	���� real,
	����������_�������_��_������ int,
	��������_������	nvarchar(50),
	���������� nvarchar(50),
	ID_���������� int foreign key references ��������� (ID_����������)
) ON FG_S����;

create table �����
(	ID_������ int primary key not null,
	����������_����������_������� int,
	ID_��������� int foreign key references �������� (ID_���������),
	ID_������ int foreign key references ����� (ID_������)
) ON FG_Zakaz;

ALTER Table �������� ADD POL nvarchar(1) default '�' check (POL in ('�', '�'));
ALTER Table �������� DROP Column POL;
insert into �������� (ID_���������, ����_������, ���_���������, �������_���������)
values (1, '2000-11-11', 'Vadim', 'Berezka'),
(2, '2012-12-12', 'Vlad', 'Shumskyi'),
(3, '2020-2-2', 'Semen', 'Pozin');

insert into ��������� (ID_����������, ��������, �����, �������)
values (11, '����', '���������', '+375299780571'),
(22, '����', '������', '+375299780572'),
(33, '���', '���������', '+375299780573');

insert into ����� (ID_������, �������, ����, ����������_�������_��_������, ��������_������, ����������, ID_����������)
values
(111, 123456, 25.50, 100, '����', '������', 11),
(222, 654321, 15.75, 200, '����', '��� �����', 22),
(333, 112233, 45.00, 50, '��', '�� ��� �����', 33);

insert into ����� (ID_������, ����������_����������_�������, ID_���������, ID_������)
values
(1111, 2, 1, 111),
(2222, 1, 2, 222),
(3333, 2, 1, 333);


SELECT * From �����; 
SELECT ����_������ From ��������; 
SELECT count(*) From �����; 


UPDATE ����� set ����������_�������_��_������ = ����������_�������_��_������+5 Where ������� = 123456;
SELECT ����������_�������_��_������ From �����; 















USE master;
CREATE DATABASE Ber_MyBase
ON PRIMARY
(
    NAME = Ber_MyBase_Data,
    FILENAME = 'C:\University\��\���3\Ber_MyBase_Data.mdf',
    SIZE = 10MB,
    MAXSIZE = 100MB,
    FILEGROWTH = 5MB
)
LOG ON
(
    NAME = Ber_MyBase_Log,
    FILENAME = 'C:\University\��\���3\Ber_MyBase_Log.ldf',
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
    FILENAME = 'C:\University\��\���3\Ber_MyBase_Sklad_Data.ndf',
    SIZE = 5MB,
    MAXSIZE = 50MB,
    FILEGROWTH = 5MB
) TO FILEGROUP FG_Sklad;

ALTER DATABASE Ber_MyBase
ADD FILE
(
    NAME = Ber_MyBase_Zakaz_Data,
    FILENAME = 'C:\University\��\���3\Ber_MyBase_Zakaz_Data.ndf',
    SIZE = 5MB,
    MAXSIZE = 50MB,
    FILEGROWTH = 5MB
) TO FILEGROUP FG_Zakaz;

ALTER DATABASE Ber_MyBase
ADD FILE
(
    NAME = Ber_MyBase_Postavshchik_Data,
    FILENAME = 'C:\University\��\���3\Ber_MyBase_Postavshchik_Data.ndf',
    SIZE = 5MB,
    MAXSIZE = 50MB,
    FILEGROWTH = 5MB
) TO FILEGROUP FG_Postavshchik;