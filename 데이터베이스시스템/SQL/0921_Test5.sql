
if object_id('dbo.triple', 'U') is not null drop table dbo.triple;
create table triple (a int, b int, c int);
go

declare @a int, @b int, @c int;
set @a = 1;
set @b = 1;
set @c = 1;

while @c < 500
	begin
	set @b = 1;
		while @b < 500
			begin
			set @a = 1;
				while @a < 500
					begin
						if( @a*@a + @b*@b = @c*@c )
							insert into dbo.triple(a,b,c) values (@a, @b, @c);
						else if( @a*@a + @b*@b > @c*@c )
							break;
						else if( @a*@a + @b*@b < @c*@c )
							set @a = @a + 1;
					end
			if( @a*@a + @b*@b > @c*@c )
				break;
			else
				set @b = @b + 1;
			end
		set @c = @c + 1;
	end
go
