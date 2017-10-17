use CSE_DEPT
GO
EXEC sp_columns @table_name = N'Student'
	,@table_owner=N'dbo'