--create table #SUBJECT
--(
--	code_S char(10) primary key,
--	name_S varchar(100),
--	name_P char(20)
--)

alter procedure PSUBJECT @p varchar(20) = null
as
begin
	print('���������: @p = ' + @p);
	declare @count int = (select count(*) from SUBJECT),
			@count2 int = (select count(*) from SUBJECT s where s.PULPIT = @p);
	print('�� ' + cast(@count as varchar(3)) + ' ������� �������� ' + cast(@count2 as varchar(3)) + ' �������.');
	select * from SUBJECT s where s.PULPIT = @p;
end;

insert #SUBJECT exec PSUBJECT @p = '����';

select * from #SUBJECT;

DROP PROCEDURE PSUBJECT;
