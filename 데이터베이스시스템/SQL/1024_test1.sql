use CSE_DEPT
go


/*
enable trigger trdeleteFaculty on Faculty

-- 트리거 enable 방법
*/

CREATE TRIGGER ddl_trig_database1
ON ALL SERVER
FOR CREATE_DATABASE, DROP_DATABASE
AS
PRINT 'Database Created or Droped.'
SELECT EVENTDATA().value('(/EVENT_INSTANCE/TSQLCommand/CommandText)[1]','nvarchar(max)')
GO
--실행하면 서버개체 - 트리거에 생성됨
-- 이후 데이터베이스를 생성/드랍하면 메세지를 출력하게됨
