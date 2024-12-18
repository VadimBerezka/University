CREATE VIEW ПРЕПОДАВАТЕЛИ AS
SELECT TEACHER AS код,
    TEACHER_NAME AS имя_преподавателя,
    GENDER AS пол,
    PULPIT AS код_кафедры
FROM TEACHER;