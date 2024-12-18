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
PRINT '���������� ����� � ������� Y: ' + CAST(@c AS VARCHAR(2));

IF @flag = 'c' 
    COMMIT;
ELSE 
    ROLLBACK;

SET IMPLICIT_TRANSACTIONS OFF

IF EXISTS (SELECT * FROM SYS.OBJECTS 
           WHERE OBJECT_ID = OBJECT_ID(N'DBO.Y'))
    PRINT '������� Y ����';
ELSE 
    PRINT '������� Y ���';

SELECT * FROM Y;


-- 2
BEGIN TRY
    BEGIN TRANSACTION;

    INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) 
    VALUES ('���', '���������� ������� ����������', '�', '����');

    UPDATE STUDENT 
    SET NAME = '����� ������� �������� (���������)'
    WHERE IDSTUDENT = 1001;

    INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) 
    VALUES ('����', '������ �������� �������������', '�', '����');

    COMMIT TRANSACTION;

END TRY
BEGIN CATCH
    DECLARE @ErrorMessage NVARCHAR(4000);
    SELECT @ErrorMessage = ERROR_MESSAGE();

    PRINT '������: ' + @ErrorMessage;
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
    VALUES ('��', '������������ ���������');

    SET @point1 = 'SavePoint1'; 
    SAVE TRANSACTION @point1;

    INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) 
    VALUES ('��', '������ ����� ���������', '�', '����');

    SET @point2 = 'SavePoint2'; 
    SAVE TRANSACTION @point2;

    INSERT INTO TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) 
    VALUES ('��', '������ ����� ��������� (��������)', '�', '����');

    COMMIT TRANSACTION;

END TRY
BEGIN CATCH
    DECLARE @ErrorMessage NVARCHAR(4000);
    SELECT @ErrorMessage = ERROR_MESSAGE();
    PRINT '������: ' + @ErrorMessage;

    IF @@TRANCOUNT > 0
    BEGIN
        IF XACT_STATE() > 0
        BEGIN
            ROLLBACK TRANSACTION @point2; 
            PRINT '����� � ����������� ����� ' + @point2 + ' ��������.';
        END
        ELSE
        BEGIN
            ROLLBACK TRANSACTION; 
            PRINT '���������� ��������� ��������.';
        END
    END
END CATCH;

SELECT * FROM FACULTY;
SELECT * FROM TEACHER;
DELETE FACULTY WHERE FACULTY = '��';
DELETE TEACHER WHERE TEACHER = '��';
GO


-- 4
DELETE FROM PROGRESS WHERE IDSTUDENT = 1001;
-- A
BEGIN TRANSACTION;
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
------ t1 ---------
SELECT @@SPID [SPID], 'INSERT RESULT' [insert result], * FROM PROGRESS WHERE SUBJECT = '����' 
SELECT @@SPID, 'UPDATE RESULT', * FROM PROGRESS WHERE SUBJECT = '����'
COMMIT;
-- t2 ---
GO



-- 5
-- A
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
BEGIN TRANSACTION;

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (3, '�����', '2006-05-17');

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (3, '����', '2005-06-18');

SELECT COUNT(*) AS '���������� ���������' FROM STUDENT WHERE NAME = '�����';
-------------------------- t1 ------------------ 
-------------------------- t2 -----------------
SELECT '���������� ���������' AS '���������', COUNT(*)
FROM STUDENT WHERE NAME = '�����';
COMMIT;	

-- 6
-- A
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
BEGIN TRANSACTION;

SELECT NAME FROM STUDENT WHERE IDGROUP = 3;

-------------------------- t1 ------------------ 
-------------------------- t2 -----------------
SELECT CASE
    WHEN NAME = '�����' THEN '���������' 
    ELSE ' ' 
END AS '���������', NAME 
FROM STUDENT WHERE IDGROUP = 3;

COMMIT;



-- 7
-- A
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRANSACTION;

DELETE FROM STUDENT WHERE NAME = '����';

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, '�������', '2001-05-15');

UPDATE STUDENT SET NAME = '����' WHERE NAME = '�������';

SELECT NAME FROM STUDENT WHERE IDGROUP = 1;

-------------------------- t1 -----------------
SELECT NAME FROM STUDENT WHERE IDGROUP = 1;
-------------------------- t2 ------------------ 

COMMIT;


-- 8
BEGIN TRANSACTION;

BEGIN TRANSACTION;

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, '�����', '2002-03-15');

BEGIN TRANSACTION;

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, '������', '2002-06-20');

ROLLBACK; 

COMMIT;  

SELECT COUNT(*) FROM STUDENT WHERE IDGROUP = 1;

COMMIT;