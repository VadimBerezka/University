--4
--B
BEGIN TRANSACTION
SELECT @@SPID

INSERT PROGRESS VALUES ('СУБД', 1001, '2013-01-10', 10)
UPDATE PROGRESS SET NOTE = 9 WHERE SUBJECT = 'СУБД' AND IDSTUDENT = 1001
------ t1 ---------
------ t2 ---------
ROLLBACK;
GO

--5
-- B
BEGIN TRANSACTION; 
-------------------------- t1 --------------------
UPDATE STUDENT SET NAME = 'Вадим' WHERE NAME = 'Леша';
COMMIT; 
-------------------------- t2 --------------------

SELECT * FROM STUDENT;
DELETE STUDENT WHERE NAME = 'Вадим';

--6
-- B
BEGIN TRANSACTION; 

-------------------------- t1 --------------------
INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, 'Александр', '2001-05-15');

COMMIT; 

-------------------------- t2 --------------------
SELECT * FROM STUDENT;

--7
-- B
BEGIN TRANSACTION;

DELETE FROM STUDENT WHERE NAME = 'Иван';

INSERT INTO STUDENT (IDGROUP, NAME, BDAY) 
VALUES (1, 'Сергей', '2001-08-20');

UPDATE STUDENT SET NAME = 'Александр' WHERE NAME = 'Сергей';

SELECT NAME FROM STUDENT WHERE IDGROUP = 1;

-------------------------- t1 --------------------
COMMIT;

SELECT NAME FROM STUDENT WHERE IDGROUP = 1;
-------------------------- t2 --------------------
