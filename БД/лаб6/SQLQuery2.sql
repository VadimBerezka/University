USE Ber_MyBase;

-- 1. ������� ���������� �������, ��������, �������, ������� � ����� ���������� ������� ��� ������� �������.
SELECT ZC.���_���������,
    COUNT(Z.ID_������) AS [���������� �������],
    MAX(Z.����������_����������_�������) AS [��������],
    MIN(Z.����������_����������_�������) AS [�������],
    AVG(Z.����������_����������_�������) AS [�������],
    SUM(Z.����������_����������_�������) AS [�����]
FROM ����� Z INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
GROUP BY ZC.���_���������;

-- 2. ����������, ������� ������� ���������� ������ ���������.
SELECT PS.�������� AS [���������],
    COUNT(S.ID_������) AS [���������� �������]
FROM ��������� PS LEFT JOIN ����� S ON PS.ID_���������� = S.ID_����������
GROUP BY PS.��������;

-- 3. ��������� ������� ���� ������� ��� ������� ���������� � ��������� �� ��������.
SELECT PS.�������� AS [���������],
    ROUND(AVG(S.����), 2) AS [������� ����]
FROM ��������� PS INNER JOIN ����� S ON PS.ID_���������� = S.ID_����������
GROUP BY PS.��������
ORDER BY [������� ����] DESC;

-- 4. ���������� ����� ���������� ���������� ������� ��� ������� ������������ ������.
SELECT S.��������_������,
    SUM(Z.����������_����������_�������) AS [���������� ����������]
FROM ����� Z INNER JOIN ����� S ON Z.ID_������ = S.ID_������
GROUP BY S.��������_������
ORDER BY [���������� ����������] DESC;

-- 5. ������� ���������� ������� � ����� ���������� ������� �� ������ ����.
SELECT ZC.����_������,
    COUNT(Z.ID_������) AS [���������� �������],
    SUM(Z.����������_����������_�������) AS [����� �������]
FROM ����� Z INNER JOIN �������� ZC ON Z.ID_��������� = ZC.ID_���������
GROUP BY ZC.����_������
ORDER BY ZC.����_������ DESC;