create procedure PAUDITORIUM_INSERT @a char(20), @n varchar(50), @c int = 0, @t char(10)
as
begin
	begin try
		insert into AUDITORIUM
					values(@a, @n, @c, @t);
		return 1;
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
		return -1;
	end catch
end;	

declare @inProc int;

exec @inProc = PAUDITORIUM_INSERT @a = '1223-1', @n = 'ЛК', @c = 40, @t = 'AUD';
print('Успех: ' + cast(@inProc as varchar(3)));
exec @inProc = PAUDITORIUM_INSERT @a = '1443-1', @n = 'ЛeК', @c = 99, @t = 'ttt';
print('Успех: ' + cast(@inProc as varchar(3)));
exec @inProc = PAUDITORIUM_INSERT @a = '1-1', @n = 'ЛБ-К', @c = 100, @t = 'AUD2';
print('Успех: ' + cast(@inProc as varchar(3)));
exec @inProc = PAUDITORIUM_INSERT @a = '999-1', @n = 'ЛБ-СК', @c = 400, @t = 'AUD3';
print('Успех: ' + cast(@inProc as varchar(3)));

select * from AUDITORIUM;

delete from AUDITORIUM where AUDITORIUM like '1223-1'; 
delete from AUDITORIUM where AUDITORIUM like '1-1'; 