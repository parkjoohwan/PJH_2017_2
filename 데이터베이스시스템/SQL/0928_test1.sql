use CSE_DEPT
go


if object_id('dbetween') is not null
drop function dbetween
go

create function dbetween(@d1 date, @d2 date)
returns @dates table(dno int, dd date)
as
begin
declare @i int;
set @i = 1;
	while( @d1 <= @d2)
	begin
	insert into @dates(dno, dd) values(@i, @d1);
	set @i = @i +1;
	set @d1 = dateadd(day,1,@d1);
	end

	return
end