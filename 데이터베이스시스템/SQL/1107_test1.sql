use CSE_DEPT
go

create procedure curproc
as
begin
declare @cid varchar(50)
declare @cname varchar(50)
declare @croom varchar(50)

-- step1 declaring a cursor using a query
declare my_cursor cursor for
select course_id, course, classroom
from course
order by course

-- step2
open my_cursor;
print @@CURSOR_ROWS

-- step3 feching first row from thew cursor into local variables
fetch next from my_cursor
into @cid, @cname, @croom

--step4 process rows
while( @@FETCH_STATUS = 0 )
	begin
		print @cid + '    ' + @cname +  '    ' + @croom
		fetch next from my_cursor
		into @cid, @cname, @croom
	end

--setp5 close the cursor
close my_cursor

--setp6 deallocate memory
deallocate my_cursor


end

--exec dbo.curproc xsd