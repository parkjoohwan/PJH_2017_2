
declare @i int;
set @i = 45;
if @i = 10
	print 'ture'
else if not ( @i = 10 )
	print 'false'
else
	print 'unknown'

if year(sysdatetime()) <> year(dateadd(day, 1, sysdatetime()))
	print 'today is the last day of the year.'
else
	print 'today is not the last day of the year.'

if year(sysdatetime()) <> year(dateadd(day, 1, sysdatetime()))
	print 'today is the last day of the year.'
else
	if month(sysdatetime()) <> month(dateadd(day, 1, sysdatetime()))
		print 'today is the last day of the month but not the last day of the year.'
	else
		print 'today is not the last day of the month.'

declare @j int = 1;
while @j <= 10
begin
	print @j;
	set @j = @j + 1;
end



declare @b int = 1;
while @b <= 10
begin
	print @b;
	set @b = @b + 1;

continue; -- force the while loop to restart

print ' the continue keyword ensures that this will never be printed.'

end

declare @k as int = 1;
while @k <= 10
begin
	if @k = 6 break;
	print @k;
	set @k = @k + 1;
end;