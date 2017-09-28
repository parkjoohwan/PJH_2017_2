


set nocount on;
if object_id('dbo.Numbers', 'U') is not null drop table dbo.Numbers;
create table Numbers (id int, name varchar(20) );
go

declare @i as int = 1;
while @i <= 1000
	begin
		insert into dbo.Numbers(id, name) values (@i, 'abc');
		set @i = @i +1;
	end
go