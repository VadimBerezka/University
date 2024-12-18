CREATE VIEW Дисциплины AS
SELECT TOP 10
    SUBJECT AS код,
    SUBJECT_NAME AS наименование_дисциплины,
    PULPIT AS код_кафедры
FROM SUBJECT
ORDER BY SUBJECT_NAME;