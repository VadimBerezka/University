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
			raiserror('Ошибка в параметрах!', 11, 1) 
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
		print('Список дисциплин для кафедры : ' + @p);
		print(space(3) + @resStr);
		return @count;
	end try

	begin catch
		print 'Ошибка в параметрах!';
		if ERROR_PROCEDURE() is not null
		begin
			print 'Имя процедуры : ' + error_procedure();
		end;
		return @locCount;
	end catch
end;

declare @result int = 0;

exec @result = SUBJECT_REPORT @p = 'ИСиТ';
print('Количество дисциплин: ' + cast(@result as varchar(3)));

exec @result = SUBJECT_REPORT @p = 'fail';
print('Количество дисциплин: ' + cast(@result as varchar(3)));

drop procedure SUBJECT_REPORT;