CREATE VIEW ����������_�������_��_��������� WITH SCHEMABINDING AS
SELECT ID_��������� AS ���_���������,
	COUNT(ID_������) AS ����������_�������
FROM �����
GROUP BY ID_���������;