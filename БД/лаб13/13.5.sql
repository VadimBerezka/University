create procedure SUBJECT_REPORT @p char(10)
as
begin
	begin try
		declare subj cursor local static 
				for select s.SUBJECT from SUBJECT s where s.PULPIT = @p;
		declare @count int = (select count(*) from SUBJECT s where s.PULPIT like @p),
				@resStr varchar(300) = '',
				@locSubj varchar(50) = '',
				@locCount int = 0;
		if(@count = 0)
		begin
			raiserror('������ � ����������!', 11, 1) 
		end;
		open subj;
		fetch subj into @locSubj;
		while(@@FETCH_STATUS = 0)
		begin
			set @resStr = concat(trim(@locSubj), ', ', @resStr);
			fetch subj into @locSubj;
			set @locCount = @locCount + 1;  
		end;
		close subj;
		print('������ ��������� ��� ������� : ' + @p);
		print(space(3) + @resStr);
		return @count;
	end try

	begin catch
		print '������ � ����������!';
		if ERROR_PROCEDURE() is not null
		begin
			print '��� ��������� : ' + error_procedure();
		end;
		return @locCount;
	end catch
end;

declare @result int = 0;

exec @result = SUBJECT_REPORT @p = '����';
print('���������� ���������: ' + cast(@result as varchar(3)));

exec @result = SUBJECT_REPORT @p = 'fail';
print('���������� ���������: ' + cast(@result as varchar(3)));

drop procedure SUBJECT_REPORT;