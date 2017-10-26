use CSE_DEPT
go

CREATE TRIGGER safety
ON DATABASE
FOR CREATE_TABLE
AS
	PRINT 'CREATE TABLE Issued.'
	SELECT EVENTDATA().value('(/EVENT_INSTANCE/TSQLCommand/CommandText)[1]','nvarchar(max)')
	RAISERROR ('New tables cannot be created in this database.', 16, 1)
ROLLBACK;

-- �ش� �����ͺ��̽��� ���̺��� �����Ǹ� �޼����� ������ش�.
-- �����ͺ��̽��� ���̺��� �������� ���ϰ� ����
