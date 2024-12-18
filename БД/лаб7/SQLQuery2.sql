USE Ber_MyBase;

-- 1
SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������, 
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������ WITH ROLLUP
ORDER BY ZC.���_���������, ZC.�������_���������, SK.��������_������;

-- 2
SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������,
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������ WITH CUBE
ORDER BY ZC.���_���������, ZC.�������_���������, SK.��������_������;

-- 3
SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������, 
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
WHERE ZC.���_��������� LIKE 'V%'
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������;

SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������, 
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
WHERE ZC.���_��������� LIKE 'S%'
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������;

SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������, 
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
WHERE ZC.���_��������� LIKE 'V%'
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������

UNION ALL

SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������, 
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
WHERE ZC.���_��������� LIKE 'S%'
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������;

-- 4
SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������, 
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
WHERE ZC.���_��������� LIKE 'V%'
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������

INTERSECT

SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������, 
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
WHERE ZC.���_��������� LIKE 'S%'
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������;

-- 5
SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������, 
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
WHERE ZC.���_��������� LIKE 'V%'
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������

EXCEPT

SELECT ZC.���_���������, ZC.�������_���������, SK.��������_������, 
	ROUND(AVG(SK.����), 2) AS �������_����
FROM ����� Z
INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
INNER JOIN ����� SK ON Z.ID_������ = SK.ID_������
WHERE ZC.���_��������� LIKE 'S%'
GROUP BY ZC.���_���������, ZC.�������_���������, SK.��������_������;