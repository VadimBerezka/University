USE Ber_MyBase;

-- 1
SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали, 
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали WITH ROLLUP
ORDER BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали;

-- 2
SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали,
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали WITH CUBE
ORDER BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали;

-- 3
SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали, 
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
WHERE ZC.Имя_заказчика LIKE 'V%'
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали;

SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали, 
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
WHERE ZC.Имя_заказчика LIKE 'S%'
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали;

SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали, 
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
WHERE ZC.Имя_заказчика LIKE 'V%'
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали

UNION ALL

SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали, 
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
WHERE ZC.Имя_заказчика LIKE 'S%'
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали;

-- 4
SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали, 
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
WHERE ZC.Имя_заказчика LIKE 'V%'
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали

INTERSECT

SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали, 
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
WHERE ZC.Имя_заказчика LIKE 'S%'
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали;

-- 5
SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали, 
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
WHERE ZC.Имя_заказчика LIKE 'V%'
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали

EXCEPT

SELECT ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали, 
	ROUND(AVG(SK.Цена), 2) AS Средняя_Цена
FROM ЗАКАЗ Z
INNER JOIN ЗАКАЗЧИК ZC ON Z.ID_заказчика = ZC.ID_заказчика
INNER JOIN СКЛАД SK ON Z.ID_детали = SK.ID_детали
WHERE ZC.Имя_заказчика LIKE 'S%'
GROUP BY ZC.Имя_заказчика, ZC.Фамилия_заказчика, SK.Название_детали;