/* поправить */
USE [LAB6]
GO
/****** Object:  StoredProcedure [dbo].[PSUBJECT]    Script Date: 02.12.2024 22:21:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[PSUBJECT] @p nvarchar(20) = NULL , @c int OUTPUT
as
begin
	declare @a nvarchar(50) = (select count(*) FROM SUBJECT);
	print 'параметры @p = ' +  @p +' , @c = ' + cast(@c as varchar(3));
	select SUBJECT.SUBJECT , SUBJECT.SUBJECT_NAME , SUBJECT.PULPIT FROM SUBJECT where SUBJECT.PULPIT = @p;
	set @c = @@ROWCOUNT;
	return @a;
end;
DECLARE @resultCount INT;  

EXEC @resultCount = PSUBJECT @p = 'ИСиТ', @c = @resultCount OUTPUT;

SELECT @resultCount AS TotalSubjects;
