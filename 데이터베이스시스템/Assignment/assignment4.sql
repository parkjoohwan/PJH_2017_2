use Mydatabase
go

create procedure calsalay ( @nyear varchar(3), @nmonth varchar(2))
-- make store procedure takes two input parameter
as
begin

declare @bpay  numeric(10,2)
declare @pcode varchar(3)
declare @pdesc varchar(50)

-- save total payment, deductions, salary
declare @total_pay numeric(10,2)
declare @total_dec numeric(10,2)
declare @total_sal numeric(10,2)


-- step1 declaring a cursor using a query
-- basic pay is given in Employee table under the column/attribute bpay
declare my_cursor cursor for
select bpay
from Employee

declare my_cursor2 cursor for
select pcode, pdesc 
from PayCodes
order by pcode

-- step2
open my_cursor;
open my_cursor2;

-- step3 feching first row from thew cursor into local variables
fetch next from my_cursor2
into @eid, @ename, @bpay

fetch next from my_cursor2
into @pcode, @pdesc

--step4 process rows
print 'year   ' + @nyear + ' / month  ' + @nmonth + '  pay slip  ' + @ename 
print 'payment items      payment       deductions      deductible'
while( @@FETCH_STATUS = 0 )
begin
		fetch next from my_cursor
				into @eid, @ename, @bpay
				fetch next from my_cursor2
				into @pcode, @pdesc
		if( @bpay > 3000 )
		begin
			if( @pcode between 101 and 500 ) 
			-- if basic pay < 3000, the payment (101~500) for each head will be 10% of the basic pay
			-- and the deductions (501 ~ 999 ) for each head will be 7%
			begin
				print @pdesc + '     ' + cast((@bpay*0.1) as varchar) + '  '
				set @total_pay =+ @bpay*0.1
			end
			if( @pcode between 501 and 999 )
			begin
				print @pdesc + '  ' + cast((@bpay*0.07) as varchar)+ '  '
				set @total_dec =+ @bpay*0.07
			end
		end
			else if( @bpay <= 3000 )
			-- if basic pay < 3000, the payment (101~500) for each head will be 15% of the basic pay
			-- and the deductions (501 ~ 999 ) for each head will be 10%
		begin
			if( @pcode between 101 and 500 )
			begin
				print @pdesc + '     ' + cast((@bpay*0.15) as varchar)+ '  '
				set @total_pay =+ @bpay*0.15
			end
			if( @pcode between 501 and 999 )
			begin
				print @pdesc + '  ' + cast((@bpay*0.1) as varchar) + '  '
				set @total_dec =+ @bpay*0.1
			end
		end
		print 'total payment   ' + @total_pay + 'total deductions' + @total_dec
		print 'total salary         ' + (@total_pay - @total_dec)		--total salary = total payment - total deductions
end



--setp5 close the cursor
close my_cursor
close my_cursor2
--setp6 deallocate memory
deallocate my_cursor
deallocate my_cursor2

end
