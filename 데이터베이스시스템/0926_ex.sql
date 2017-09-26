declare @a varchar (20 ) ='abc';
declare @d datetime = getdate();
declare @i int;

set @i=convert(int,@d);

select @i;

declare @myval decimal (5,2)
set @myval = 193.57

select convert(decimal(10,5), convert(varbinary(20), @myval))

select cast(cast(@myval as varbinary(20)) as decimal(10,3))

select datepart(year, getdate())
select datepart(week, getdate())
select datepart(dd, getdate())
select datepart(mm, getdate())

