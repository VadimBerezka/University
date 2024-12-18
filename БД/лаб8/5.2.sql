CREATE VIEW Количество_заказов_по_заказчику AS
SELECT ID_заказчика AS Код_заказчика,
	COUNT(ID_заказа) AS Количество_заказов
FROM ЗАКАЗ
GROUP BY ID_заказчика;