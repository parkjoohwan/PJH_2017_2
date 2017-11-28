use CSE_DEPT
go

BEGIN TRANSACTION T1
select * from Faculty

DELETE FROM Faculty
	WHERE faculty_id = 'asdf';

	select * from Faculty

COMMIT;