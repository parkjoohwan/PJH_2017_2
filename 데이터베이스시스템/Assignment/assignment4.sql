use Mydatabase
go

insert into Employee values ('E0001','pseron1',5000);
insert into Employee values ('E0002','person2',3000);
insert into Employee values ('E0003','person3',4000);
insert into PayCodes values ('101','Basic pay');
insert into PayCodes values ('102','Research allowance');
insert into PayCodes values ('105','jeonggeun incentive payments');
insert into PayCodes values ('106','Chinese subsidy');
insert into PayCodes values ('150','Family allowances');
insert into PayCodes values ('111','Research subsidy');
insert into PayCodes values ('501','Health insurance');
insert into PayCodes values ('502','Teachers pension');
insert into PayCodes values ('503','Circles');
insert into PayCodes values ('551','income tax');
insert into PayCodes values ('552','resident tax');

if object_id('calsalary','P') is not null
drop procedure calsalary
go

create procedure calsalary ( @nyear varchar(4), @nmonth varchar(2))
-- make store procedure takes two input parameter
as
begin
	declare @eid varchar(10)
	declare @ename varchar(50)
	declare @bpay numeric(10,2)
	declare @pcode varchar(3)
	declare @pdesc varchar(50)
	declare @samt numeric(10,2)


-- step1 declaring a cursor using a query
-- basic pay is given in Employee table under the column/attribute bpay
	declare my_cursor_emp cursor for -- cursor for Employee table
	select eid,ename,bpay from Employee
	open my_cursor_emp
	fetch next from my_cursor_emp into @eid,@ename,@bpay

	declare my_cursor_pay cursor for --cursor for PayCodes table
	select pcode,pdesc from PayCodes


--step4 process rows
	while(@@FETCH_STATUS=0)
	begin
		open my_cursor_pay
		fetch next from my_cursor_pay into @pcode,@pdesc
		while(@@FETCH_STATUS=0) -- calculate amount
			begin

			if( @bpay < 3000 )
			begin
			-- if basic pay < 3000, the payment (101~500) for each head will be 10% of the basic pay
			-- and the deductions (501 ~ 999 ) for each head will be 7%
				if( @pcode = 101 )
					set @samt = @bpay
				else if( @pcode between 102 and 500 ) 
					set @samt  = @bpay*0.1
				else if( @pcode between 501 and 999 )
					set @samt  = @bpay*0.07
			end
			else if( @bpay >= 3000 )
			begin
			-- if basic pay < 3000, the payment (101~500) for each head will be 15% of the basic pay
			-- and the deductions (501 ~ 999 ) for each head will be 10%
				if( @pcode = 101 )
					set @samt = @bpay
				else if( @pcode between 102 and 500 ) 
						set @samt  = @bpay*0.15
				else if( @pcode between 501 and 999 )
					set @samt  = @bpay*0.1
			end
				insert into Salary values (@nyear,@nmonth,@eid,@pcode,@samt)
				fetch next from my_cursor_pay into @pcode,@pdesc
		end
	
		close my_cursor_pay
		fetch next from my_cursor_emp into @eid,@ename,@bpay
	end	

	close my_cursor_emp

--print pay slip
	declare my_cursor_sal cursor for --cursor for Salary table
	select seid,spcode,samt from Salary

	open my_cursor_emp
	fetch next from my_cursor_emp into @eid,@ename,@bpay

	declare @Fcureid varchar(10)  --current eid, use in my_cursor_sal

	while(@@FETCH_STATUS=0)
		begin
			open my_cursor_sal
			fetch next from my_cursor_sal into @Fcureid,@pcode,@samt

			set @ename = (select ename from Employee where eid=@eid)
			print '==========Year : '+@nyear+ ' / Month : '+@nmonth+'      Pay Slip   '+@ename

			declare @Psum int
			set @Psum=0
			declare @Dsum int
			set @Dsum=0

			while(@@FETCH_STATUS=0)
				begin
					if(@Fcureid=@eid and @pcode<=500)
						begin
						set @pdesc = (select pdesc from PayCodes where pcode=@pcode)
						print '('+@pcode+')' + @pdesc + '     '+convert(varchar(11),@samt)
						set @Psum+=@samt
						end
					else if(@Fcureid=@eid and @pcode>500)
						begin
						set @pdesc = (select pdesc from PayCodes where pcode=@pcode)
						print '('+@pcode+')' + @pdesc + '     '+convert(varchar(11),@samt)
						set @Dsum+=@samt
						end
					fetch next from my_cursor_sal into @Fcureid,@pcode,@samt
				end
			print 'total payments : '+convert(varchar(11),@Psum)+ ' / total dedections : '+convert(varchar(11),@Dsum)
			print 'Total Salary : ' + convert(varchar(11),@Psum-@Dsum)
			print ''
			close my_cursor_sal
			fetch next from my_cursor_emp into @eid,@ename,@bpay
		end
end
go


execute calsalary '2017','11'

delete from Employee
delete from PayCodes
delete from Salary
close my_cursor_emp
deallocate my_cursor_emp
deallocate my_cursor_pay
deallocate my_cursor_sal