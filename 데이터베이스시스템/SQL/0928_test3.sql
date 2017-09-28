create function dbo.CalculateArea(@radius as float)
returns float
as
begin
return PI()* power(@radius,2);
end;