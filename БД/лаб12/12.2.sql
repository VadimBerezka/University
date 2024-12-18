--4
--B
BEGIN TRANSACTION
SELECT @@SPID

INSERT PROGRESS VALUES ('����', 1001, '2013-01-10', 10)
UPDATE PROGRESS SET NOTE = 9 WHERE SUBJECT = '����' AND IDSTUDENT = 1001
------ t1 ---------
------ t2 ---------
ROLLBACK;
GO

--5
-- B
BEGIN TRANSACTION; 
-------------------------- t1 --------------------
UPDATE STUDENT SET NAME = '�����' WHERE NAME = '����';
COMMIT; 
-------------------------- t2 --------------------

SELECT * FROM STUDENT;
DELETE STUDENT WHERE NAME = '�����';

--6
-- B
BEGIN TRANSACTION; 

-------------------------- t1 --------------------
INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, '���������', '2001-05-15');

COMMIT; 

-------------------------- t2 --------------------
SELECT * FROM STUDENT;

--7
-- B
BEGIN TRANSACTION;

DELETE FROM STUDENT WHERE NAME = '����';

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, '������', '2001-08-20');

UPDATE STUDENT SET NAME = '���������' WHERE NAME = '������';

SELECT NAME FROM STUDENT WHERE IDGROUP = 1;

-------------------------- t1 --------------------
COMMIT;

SELECT NAME FROM STUDENT WHERE IDGROUP = 1;
-------------------------- t2 --------------------
