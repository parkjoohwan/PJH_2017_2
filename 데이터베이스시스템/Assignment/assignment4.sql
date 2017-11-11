use Mydatabase
go

create procedure calsalay ( @nyear varchar(3), @nmonth varchar(2) )
as
begin

declare @eid   varchar(10)
declare @ename varchar(50)
declare @bpay  numeric(10,2)

-- step1 declaring a cursor using a query
declare my_cursor cursor for
select eid, ename, bpay
from Employee
order by eid

-- step2
open my_cursor;

-- step3 feching first row from thew cursor into local variables
fetch next from my_cursor
into @eid, @cname, @croom

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

--exec dbo.curproc