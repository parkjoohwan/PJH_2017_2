use CSE_DEPT
go


/*
enable trigger trdeleteFaculty on Faculty

-- Ʈ���� enable ���
*/

CREATE TRIGGER ddl_trig_database1
ON ALL SERVER
FOR CREATE_DATABASE, DROP_DATABASE
AS
PRINT 'Database Created or Droped.'
SELECT EVENTDATA().value('(/EVENT_INSTANCE/TSQLCommand/CommandText)[1]','nvarchar(max)')
GO
--�����ϸ� ������ü - Ʈ���ſ� ������
-- ���� �����ͺ��̽��� ����/����ϸ� �޼����� ����ϰԵ�
