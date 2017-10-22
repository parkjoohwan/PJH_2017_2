use CSE_DEPT
go

create trigger trdeleteFaculty 
on dbo.Faculty
for delete 
as
begin
declare @c1 as datetime
declare @c2 as varchar(30)
declare @c3 as varchar(30)
declare @c4 as varchar(30)
declare @c5 as varchar(MAX)

set @c1=getdate();
set @c2=SUSER_NAME();
set @c3='dbo.Faculty'
set @c4='delete'   /* delete operation */

select @c5 = CONCAT( faculty_id, ', ', faculty_name, ', ', office, ', '
					, college, ', ', title, ', ', email) from deleted; 
					/* deleted 최근에 지워진 것?? */
insert into mylogtable01 values(@c1, @c2, @c3, @c4, @c5);	/* 지워진 테이블을 로그파일에 저장*/

end
