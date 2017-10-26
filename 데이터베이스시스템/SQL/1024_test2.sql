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

-- 해당 데이터베이스에 테이블이 생성되면 메세지를 출력해준다.
-- 데이터베이스에 테이블을 생성하지 못하게 해줌
