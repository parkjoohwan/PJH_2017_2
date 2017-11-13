use Mydatabase
go

create procedure calsalay ( @nyear varchar(3), @nmonth varchar(2), @ename varchar(50) )
as
begin

declare @eid   varchar(10)
declare @bpay  numeric(10,2)
declare @name varchar(50)

declare @pcode varchar(3)
declare @pdesc varchar(50)

-- step1 declaring a cursor using a query
declare my_cursor cursor for
select pcode, pdesc 
from PayCodes
order by pcode

-- step2
open my_cursor;

-- step3 feching first row from thew cursor into local variables
fetch next from my_cursor
into @pcode, @pdesc


--step4 process rows
print 'year   ' + @nyear + ' / month  ' + @nmonth + '  pay slip  ' + @ename 
	print 'payment items      payment       deductions      deductible'
while( @@FETCH_STATUS = 0 )
begin
		if( @bpay > 3000 )
		begin
			if( @pcode between 101 and 500 )
			begin
				print @pdesc + '     ' + cast((@bpay*0.1) as varchar) + '  '
			end
			if( @pcode between 501 and 999 )
			begin
				print @pdesc + '  ' + cast((@bpay*0.07) as varchar)+ '  '
			end
		end
		else
		begin
			if( @pcode between 101 and 500 )
			begin
				print @pdesc + '     ' + cast((@bpay*0.1) as varchar)+ '  '
			end
			if( @pcode between 501 and 999 )
			begin
				print @pdesc + '  ' + cast((@bpay*0.07) as varchar) + '  '
			end
		end
end

--setp5 close the cursor
close my_cursor
--setp6 deallocate memory
deallocate my_cursor


end

--exec dbo.curproc