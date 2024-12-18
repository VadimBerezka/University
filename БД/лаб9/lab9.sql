-- 1
DECLARE @a CHAR(5) = 'first', 
        @b VARCHAR(6) = 'second';

DECLARE @c DATETIME,
        @d TIME,
        @e INT,
        @f SMALLINT,
        @g TINYINT,
        @h NUMERIC(12, 5);

SET @c = '2024-11-05 12:00:00';
SET @d = '12:00:00';
SET @e = 12345;

SELECT @f = 20000, @g = 17, @h = 54321.12345;

SELECT @a a, @b b;

PRINT 'DATETIME VALUE = ' + CAST(@c as VARCHAR(20));
PRINT 'TIME VALUE = ' + CAST(@d as VARCHAR(8));
PRINT 'INT VALUE = ' + CAST(@e as VARCHAR(5));
PRINT 'SMALLINT VALUE = ' + CAST(@f as VARCHAR(5));
PRINT 'TINYINT VALUE = ' + CAST(@g as VARCHAR(2));
PRINT 'NUMERIC VALUE = ' + CAST(@h as VARCHAR(12));

-- 2	
DECLARE @AuditoriumTable TABLE (Capacity INT);

INSERT @AuditoriumTable VALUES (100), (200), (300), (150), (250), (350);

DECLARE @TotalCapacity INT,
		@TotalAuditoriums INT,
		@AvgCapacity DECIMAL(10, 2),
		@CountBelowAvg INT,
		@PercentBelowAvg DECIMAL(5, 2);

SELECT @TotalCapacity = SUM(Capacity), @TotalAuditoriums = COUNT(*) FROM @AuditoriumTable;

IF @TotalCapacity > 200
BEGIN
    SELECT @AvgCapacity = AVG(Capacity) FROM @AuditoriumTable;
    SELECT @CountBelowAvg = COUNT(*) FROM @AuditoriumTable WHERE Capacity < @AvgCapacity;
    SET @PercentBelowAvg = (@CountBelowAvg * 100.0) / @TotalAuditoriums;

    PRINT 'Количество аудиторий: ' + CAST(@TotalAuditoriums AS VARCHAR(10));
    PRINT 'Средняя вместимость: ' + CAST(@AvgCapacity AS VARCHAR(10));
    PRINT 'Количество аудиторий, вместимость которых меньше средней: ' + CAST(@CountBelowAvg AS VARCHAR(10));
    PRINT 'Процент таких аудиторий: ' + CAST(@PercentBelowAvg AS VARCHAR(5)) + '%';
END
ELSE
BEGIN
    PRINT 'Общая вместимость аудиторий: ' + CAST(@TotalCapacity AS VARCHAR(10));
END

-- 3
SELECT  @@ROWCOUNT AS TotalRows, 
		@@VERSION AS SQLServerVersion, 
		@@SPID AS SessionProcessID, 
		@@ERROR AS LastError, 
		@@SERVERNAME AS ServerName,
		@@TRANCOUNT AS TransactionCount,
		@@FETCH_STATUS AS FetchStatus,
		@@NESTLEVEL AS NestingLevel;

-- 4
DECLARE @x INT = 4, 
        @t INT = 8, 
        @z FLOAT;    

IF (@t > @x)
BEGIN
    SET @z = POWER(SIN(@t), 2);
END 
ELSE IF (@t < @x)
BEGIN 
    SET @z = 4 * (@t + @x);
END
ELSE 
BEGIN
    SET @z = 1 - EXP(@x - 2);
END

PRINT 'Z = ' + CAST(@z AS VARCHAR);


DECLARE @FullName NVARCHAR(100) = 'Берёзка Вадим Сергеевич';
DECLARE @ShortName NVARCHAR(100);
SET @ShortName = LEFT(@FullName, CHARINDEX(' ', @FullName) - 1) + ' ' + 
                 LEFT(SUBSTRING(@FullName, CHARINDEX(' ', @FullName) + 1, LEN(@FullName)), 1) + '.' +
                 LEFT(SUBSTRING(@FullName, LEN(@FullName) - CHARINDEX(' ', REVERSE(@FullName)) + 2, LEN(@FullName)), 1) + '.';
PRINT 'ФИО: ' + @ShortName;


SELECT NAME, DATEDIFF(YEAR, BDAY, GETDATE()) AS Age	FROM STUDENT 
		WHERE MONTH(BDAY) = MONTH(DATEADD(MONTH, 1, GETDATE()));

DECLARE @IDGROUP INT = 3;
SELECT p.IDSTUDENT AS id, DATENAME(WEEKDAY, PDATE) AS day
	FROM PROGRESS p INNER JOIN STUDENT s
	ON p.IDSTUDENT = s.IDSTUDENT
	WHERE @IDGROUP = s.IDGROUP AND SUBJECT = 'ОАиП';

-- 5 
DECLARE @CAPACITY INT = (SELECT COUNT(AUDITORIUM_CAPACITY) FROM AUDITORIUM),
        @MORE INT = (SELECT COUNT(A.AUDITORIUM_TYPE) FROM AUDITORIUM A WHERE A.AUDITORIUM_CAPACITY > 60);

IF (@MORE > 0) 
BEGIN
    PRINT 'Есть аудитории, где вместимость больше 60';
END
ELSE
BEGIN
    PRINT 'Нет аудиторий, где вместимость больше 60'; 
END

-- 6
DECLARE @average INT = (SELECT AVG(NOTE) FROM FACULTY F INNER JOIN GROUPS G 
	ON F.FACULTY = G.FACULTY INNER JOIN STUDENT S 
	ON S.IDGROUP = G.IDGROUP INNER JOIN PROGRESS P 
	ON P.IDSTUDENT = S.IDSTUDENT)
SELECT CASE 
	WHEN @average BETWEEN 1 AND 4 THEN 'Плохо'
	WHEN @average BETWEEN 5 AND 8 THEN 'Хорошо'
	WHEN @average BETWEEN 9 AND 10 THEN 'Отлично'
END avg

-- 7
CREATE TABLE #TEMPTABLE 
( TIND INT,
  TFIELD INT,
  TFIELD2 INT
);

SET NOCOUNT ON;
DECLARE @counter INT = 0;
WHILE (@counter < 10)
BEGIN
    INSERT INTO #TEMPTABLE (TIND, TFIELD, TFIELD2) 
	VALUES (FLOOR(100 * RAND()), FLOOR(100 * RAND()), FLOOR(100 * RAND()));

    SELECT @counter += 1;
    PRINT @counter;
END

SELECT * FROM #TEMPTABLE
-- 8
DECLARE @xl INT = 1;
	PRINT @xl + 1
	PRINT @xl + 2
	RETURN
	PRINT @xl + 3

-- 9
BEGIN TRY
    SELECT 1 / 0;
END TRY
BEGIN CATCH 
	PRINT ERROR_NUMBER()
	PRINT ERROR_MESSAGE()
	PRINT ERROR_LINE()
	PRINT ERROR_PROCEDURE()
	PRINT ERROR_SEVERITY()
	PRINT ERROR_STATE()
END CATCH;