-- 1
CREATE FUNCTION COUNT_STUDENTS (@faculty VARCHAR(20))
RETURNS INT
AS
BEGIN
    DECLARE @student_count INT;

    SELECT @student_count = COUNT(*)
    FROM FACULTY f
    INNER JOIN GROUPS g ON f.FACULTY = g.FACULTY
    INNER JOIN STUDENT s ON g.IDGROUP = s.IDGROUP
    WHERE f.FACULTY = @faculty;

    RETURN @student_count;
END;

SELECT dbo.COUNT_STUDENTS('��') AS StudentCount;

ALTER FUNCTION COUNT_STUDENTS (
    @faculty VARCHAR(20) = NULL,
    @prof VARCHAR(20) = NULL
)
RETURNS INT
AS
BEGIN
    DECLARE @student_count INT;

    SELECT @student_count = COUNT(*)
    FROM FACULTY f
    INNER JOIN GROUPS g ON f.FACULTY = g.FACULTY
    INNER JOIN STUDENT s ON g.IDGROUP = s.IDGROUP
    INNER JOIN PROFESSION p ON g.PROFESSION = p.PROFESSION
    WHERE (@faculty IS NULL OR f.FACULTY = @faculty)
      AND (@prof IS NULL OR p.PROFESSION = @prof);

    RETURN @student_count;
END;

SELECT dbo.COUNT_STUDENTS('��', '1-36 06 01') AS StudentCount;
SELECT * FROM PROFESSION;
SELECT * FROM STUDENT;
SELECT * FROM GROUPS;

DROP FUNCTION COUNT_STUDENTS;
-- SELECT f.FACULTY, p.PROFESSION, dbo.COUNT_STUDENTS(f.FACULTY, p.PROFESSION) AS ���_��
-- FROM FACULTY f
-- INNER JOIN PROFESSION p ON f.FACULTY = p.FACULTY;

-- 2
CREATE FUNCTION FSUBJECTS(@P VARCHAR(20)) 
RETURNS VARCHAR(300) 
AS
BEGIN
    DECLARE @sb CHAR(20);  
    DECLARE @s VARCHAR(300) = '����������: ';  
    DECLARE SUBJS CURSOR LOCAL STATIC FOR 
        SELECT SUBJECT FROM SUBJECT 
        WHERE PULPIT = @P;
    
    OPEN SUBJS;    
    FETCH SUBJS INTO @sb;      
    
    WHILE @@FETCH_STATUS = 0                                     
    BEGIN 
        SET @s = @s + ', ' + RTRIM(@sb);         
        FETCH SUBJS INTO @sb; 
    END;    
    CLOSE SUBJS;
    DEALLOCATE SUBJS;

    RETURN @s;
END;

SELECT SUBJECT, dbo.FSUBJECTS(SUBJECT.PULPIT) FROM SUBJECT;

DROP FUNCTION FSUBJECTS;

-- 3
CREATE FUNCTION FFACPUL (
    @FACULTY CHAR(10) = NULL,
    @PULPIT CHAR(20) = NULL
)
RETURNS @ResultTable TABLE (
    FACULTY CHAR(10),
    FACULTY_NAME VARCHAR(50),
    PULPIT CHAR(20),
    PULPIT_NAME VARCHAR(100)
)
AS
BEGIN
    IF @FACULTY IS NULL AND @PULPIT IS NULL
    BEGIN
        INSERT INTO @ResultTable
        SELECT 
            F.FACULTY, F.FACULTY_NAME, 
            P.PULPIT, P.PULPIT_NAME
        FROM FACULTY F
        LEFT JOIN PULPIT P ON F.FACULTY = P.FACULTY;
    END
    ELSE IF @FACULTY IS NOT NULL AND @PULPIT IS NULL
    BEGIN
        INSERT INTO @ResultTable
        SELECT 
            F.FACULTY, F.FACULTY_NAME, 
            P.PULPIT, P.PULPIT_NAME
        FROM FACULTY F
        LEFT JOIN PULPIT P ON F.FACULTY = P.FACULTY
        WHERE F.FACULTY = @FACULTY;
    END
    ELSE IF @FACULTY IS NULL AND @PULPIT IS NOT NULL
    BEGIN
        INSERT INTO @ResultTable
        SELECT 
            F.FACULTY, F.FACULTY_NAME, 
            P.PULPIT, P.PULPIT_NAME
        FROM FACULTY F
        LEFT JOIN PULPIT P ON F.FACULTY = P.FACULTY
        WHERE P.PULPIT = @PULPIT;
    END
    ELSE IF @FACULTY IS NOT NULL AND @PULPIT IS NOT NULL
    BEGIN
        INSERT INTO @ResultTable
        SELECT 
            F.FACULTY, F.FACULTY_NAME, 
            P.PULPIT, P.PULPIT_NAME
        FROM FACULTY F
        LEFT JOIN PULPIT P ON F.FACULTY = P.FACULTY
        WHERE F.FACULTY = @FACULTY AND P.PULPIT = @PULPIT;
    END

    RETURN;
END;



SELECT * FROM dbo.FFACPUL(NULL, NULL);
SELECT * FROM dbo.FFACPUL('���', NULL);
SELECT * FROM dbo.FFACPUL(NULL, '��');
SELECT * FROM dbo.FFACPUL('���', '��');

DROP FUNCTION FFACPUL;

-- 4
CREATE FUNCTION FCTEACHER(@P VARCHAR(20)) 
RETURNS INT 
AS
BEGIN
    DECLARE @COUNT INT;
    
    SELECT @COUNT = COUNT(*)
    FROM PULPIT 
    INNER JOIN TEACHER ON PULPIT.PULPIT = TEACHER.PULPIT
    WHERE PULPIT.PULPIT = ISNULL(@P, PULPIT.PULPIT);
    
    RETURN @COUNT;
END;

SELECT PULPIT, DBO.FCTEACHER(PULPIT) AS [���������� ��������������] 
FROM PULPIT;
SELECT DBO.FCTEACHER(NULL) AS [����� ��������������];
SELECT * FROM TEACHER ORDER BY PULPIT;

DROP FUNCTION FCTEACHER;
