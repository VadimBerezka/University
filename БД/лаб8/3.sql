CREATE VIEW Аудитории AS 
SELECT AUDITORIUM AS код,
	AUDITORIUM_NAME AS наименование_аудитории
FROM AUDITORIUM
WHERE AUDITORIUM_TYPE LIKE 'ЛК%' with check option
insert into Аудитории values ('100-3', 'ЛК-К')
SELECT * FROM Аудитории

