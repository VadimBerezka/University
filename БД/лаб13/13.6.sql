create procedure PAUDITORIUM_INSERTX @a char(20), @n varchar(50), @c int = 0, @t char(10), @tn varchar(50)
as
begin try
	declare @rc int = 1;
	set transaction isolation level serializable
	begin tran
		insert into AUDITORIUM_TYPE
					values(@t, @tn);
		exec @rc = PAUDITORIUM_INSERT @a = @a, @n = @n, @c = @c, @t = @t
	commit tran;
	return @rc;
end try
begin catch
	print('Номер ошибки : ' + cast(error_number() as varchar(6)));
	print('Сообщение : ' + error_message());
	print('Уровень : ' + cast(error_severity() as varchar(6)));
	print('Метка : ' + cast(error_state() as varchar(8)));
	print('Номер строки : ' + cast(error_line() as varchar(8)));
	if(error_procedure() is not null)
	begin
		print('Имя процедуры : ' + error_procedure());
	end;
	if @@TRANCOUNT > 0 rollback tran;
	return -1;
end catch

declare @rc int;
exec @rc = PAUDITORIUM_INSERTX @a = '1223-1', @n = 'AUD66', @c = 40, @t = 'AUD66', @tn = 'new type';
print('Выполнение с кодом : ' + cast(@rc as varchar(3)));
exec @rc = PAUDITORIUM_INSERTX @a = '1223-1', @n = 'ЛК', @c = 40, @t = 'AUD662', @tn = 'new type2';
print('Выполнение с кодом : ' + cast(@rc as varchar(3)));

select * from AUDITORIUM;
select * from AUDITORIUM_TYPE;

delete from AUDITORIUM where AUDITORIUM like '1223-1'; 
delete from AUDITORIUM_TYPE where AUDITORIUM_TYPE like 'AUD66'; 
delete from AUDITORIUM_TYPE where AUDITORIUM_TYPE like 'AUD662'; 