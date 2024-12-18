-- 1
SET NOCOUNT ON
IF EXISTS (SELECT * FROM SYS.OBJECTS 
           WHERE OBJECT_ID = OBJECT_ID(N'DBO.Y')) 
    DROP TABLE Y;

DECLARE @c INT, @flag CHAR = 'c';
SET IMPLICIT_TRANSACTIONS ON

CREATE TABLE Y(K INT);
INSERT Y VALUES (4), (5), (6);
SET @c = (SELECT COUNT(*) FROM Y);
PRINT 'Количество строк в таблице Y: ' + CAST(@c AS VARCHAR(2));

IF @flag = 'c' 
    COMMIT;
ELSE 
    ROLLBACK;

SET IMPLICIT_TRANSACTIONS OFF

IF EXISTS (SELECT * FROM SYS.OBJECTS 
           WHERE OBJECT_ID = OBJECT_ID(N'DBO.Y'))
    PRINT 'Таблица Y есть';
ELSE 
    PRINT 'Таблицы Y нет';

SELECT * FROM Y;


-- 2
BEGIN TRY
    BEGIN TRANSACTION;

    INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) 
    VALUES ('НЗД', 'Незабудкин Зиновий Дмитриевич', 'м', 'ИСиТ');

    UPDATE STUDENT 
    SET NAME = 'Силюк Валерия Ивановна (обновлено)'
    WHERE IDSTUDENT = 1001;

    INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) 
    VALUES ('СМЛВ', 'Смелов Владимир Владиславович', 'м', 'ИСиТ');

    COMMIT TRANSACTION;

END TRY
BEGIN CATCH
    DECLARE @ErrorMessage NVARCHAR(4000);
    SELECT @ErrorMessage = ERROR_MESSAGE();

    PRINT 'Ошибка: ' + @ErrorMessage;
    ROLLBACK TRANSACTION;
END CATCH;

SELECT * FROM TEACHER;
SELECT * FROM STUDENT;
GO
-- 3
DECLARE @point1 VARCHAR(32);
DECLARE @point2 VARCHAR(32);

BEGIN TRY
    BEGIN TRANSACTION;

    INSERT INTO FACULTY (FACULTY, FACULTY_NAME) 
    VALUES ('МФ', 'Механический факультет');

    SET @point1 = 'SavePoint1'; 
    SAVE TRANSACTION @point1;

    INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) 
    VALUES ('ПФ', 'Петров Федор Федорович', 'м', 'ИСиТ');

    SET @point2 = 'SavePoint2'; 
    SAVE TRANSACTION @point2;

    INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) 
    VALUES ('ПФ', 'Петров Федор Федорович (дубликат)', 'м', 'ИСиТ');

    COMMIT TRANSACTION;

END TRY
BEGIN CATCH
    DECLARE @ErrorMessage NVARCHAR(4000);
    SELECT @ErrorMessage = ERROR_MESSAGE();
    PRINT 'Ошибка: ' + @ErrorMessage;

    IF @@TRANCOUNT > 0
    BEGIN
        IF XACT_STATE() > 0
        BEGIN
            ROLLBACK TRANSACTION @point2; 
            PRINT 'Откат к контрольной точке ' + @point2 + ' выполнен.';
        END
        ELSE
        BEGIN
            ROLLBACK TRANSACTION; 
            PRINT 'Транзакция полностью откатана.';
        END
    END
END CATCH;

SELECT * FROM FACULTY;
SELECT * FROM TEACHER;
DELETE FACULTY WHERE FACULTY = 'МФ';
DELETE TEACHER WHERE TEACHER = 'ПФ';
GO


-- 4
DELETE FROM PROGRESS WHERE IDSTUDENT = 1001;
-- A
BEGIN TRANSACTION;
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
------ t1 ---------
SELECT @@SPID [SPID], 'INSERT RESULT' [insert result], * FROM PROGRESS WHERE SUBJECT = 'СУБД' 
SELECT @@SPID, 'UPDATE RESULT', * FROM PROGRESS WHERE SUBJECT = 'СУБД'
COMMIT;
-- t2 ---
GO



-- 5
-- A
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
BEGIN TRANSACTION;

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (3, 'Вадим', '2006-05-17');

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (3, 'Леша', '2005-06-18');

SELECT COUNT(*) AS 'Количество студентов' FROM STUDENT WHERE NAME = 'Вадим';
-------------------------- t1 ------------------ 
-------------------------- t2 -----------------
SELECT 'Обновление студентов' AS 'Результат', COUNT(*)
FROM STUDENT WHERE NAME = 'Вадим';
COMMIT;	

-- 6
-- A
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
BEGIN TRANSACTION;

SELECT NAME FROM STUDENT WHERE IDGROUP = 3;

-------------------------- t1 ------------------ 
-------------------------- t2 -----------------
SELECT CASE
    WHEN NAME = 'Вадим' THEN 'студентик' 
    ELSE ' ' 
END AS 'результат', NAME 
FROM STUDENT WHERE IDGROUP = 3;

COMMIT;



-- 7
-- A
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRANSACTION;

DELETE FROM STUDENT WHERE NAME = 'Иван';

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, 'Алексей', '2001-05-15');

UPDATE STUDENT SET NAME = 'Петр' WHERE NAME = 'Алексей';

SELECT NAME FROM STUDENT WHERE IDGROUP = 1;

-------------------------- t1 -----------------
SELECT NAME FROM STUDENT WHERE IDGROUP = 1;
-------------------------- t2 ------------------ 

COMMIT;


-- 8
BEGIN TRANSACTION;

BEGIN TRANSACTION;

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, 'Ольга', '2002-03-15');

BEGIN TRANSACTION;

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, 'Максим', '2002-06-20');

ROLLBACK; 

COMMIT;  

SELECT COUNT(*) FROM STUDENT WHERE IDGROUP = 1;

COMMIT;