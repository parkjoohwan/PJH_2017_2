IF OBJECT_ID('dbo.GetAge') IS NOT NULL DROP FUNCTION
dbo.GetAge;
GO

CREATE FUNCTION dbo.GetAge(@birthdate AS DATE)

RETURNS INT
AS
BEGIN

RETURN DATEDIFF(year, @birthdate, sysdatetime());

END;
GO