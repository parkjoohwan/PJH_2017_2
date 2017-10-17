use CSE_DEPT
GO
EXEC sp_column_privileges @table_name = 'Faculty'
	,@table_owner='dbo'
