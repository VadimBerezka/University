CREATE VIEW ����������_�������_��_��������� AS
SELECT ID_��������� AS ���_���������,
	COUNT(ID_������) AS ����������_�������
FROM �����
GROUP BY ID_���������;