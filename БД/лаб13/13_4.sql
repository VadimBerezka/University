create procedure PAUDITORIUM_INSERT @a char(20), @n varchar(50), @c int = 0, @t char(10)
as
begin
	begin try
		insert into AUDITORIUM
					values(@a, @n, @c, @t);
		return 1;
	end try

	begin catch
		print('����� ������ : ' + cast(error_number() as varchar(6)));
		print('��������� : ' + error_message());
		print('������� : ' + cast(error_severity() as varchar(6)));
		print('����� : ' + cast(error_state() as varchar(8)));
		print('����� ������ : ' + cast(error_line() as varchar(8)));
		if(error_procedure() is not null)
		begin
			print('��� ��������� : ' + error_procedure());
		end;
		return -1;
	end catch
end;	

declare @inProc int;

exec @inProc = PAUDITORIUM_INSERT @a = '1223-1', @n = '��', @c = 40, @t = 'AUD';
print('�����: ' + cast(@inProc as varchar(3)));
exec @inProc = PAUDITORIUM_INSERT @a = '1443-1', @n = '�e�', @c = 99, @t = 'ttt';
print('�����: ' + cast(@inProc as varchar(3)));
exec @inProc = PAUDITORIUM_INSERT @a = '1-1', @n = '��-�', @c = 100, @t = 'AUD2';
print('�����: ' + cast(@inProc as varchar(3)));
exec @inProc = PAUDITORIUM_INSERT @a = '999-1', @n = '��-��', @c = 400, @t = 'AUD3';
print('�����: ' + cast(@inProc as varchar(3)));

select * from AUDITORIUM;

delete from AUDITORIUM where AUDITORIUM like '1223-1'; 
delete from AUDITORIUM where AUDITORIUM like '1-1'; 