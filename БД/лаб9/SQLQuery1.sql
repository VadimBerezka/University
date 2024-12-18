DECLARE
@char_var char = 'A',
@varchar_var varchar(20) = 'Hello, world!',
@datetime_var datetime = GETDATE(),
@time_var time = CAST('12:34:56' AS time),
@int_var int = 1234,
@smallint_var smallint = 123,
@tinyint_var tinyint = 12,
@numeric_var numeric(12, 5) = 123.45678

SELECT
@char_var,
@varchar_var,
@datetime_var,
@time_var,
@int_var,
@smallint_var,
@tinyint_var,
@numeric_var

PRINT 'Значения переменных:'
PRINT @char_var
PRINT @varchar_var
PRINT CAST(@datetime_var AS varchar(50))
PRINT CAST(@time_var AS varchar(50))
PRINT CAST(@int_var AS varchar(50))
PRINT CAST(@smallint_var AS varchar(50))
PRINT CAST(@tinyint_var AS varchar(50))
PRINT CAST(@numeric_var AS varchar(50))


DECLARE @Rooms TABLE (
RoomID int,
Capacity int
)

INSERT INTO @Rooms VALUES
(1, 50),
(2, 75),
(3, 40),
(4, 60),
(5, 30),
(6, 80),
(7, 45),
(8, 85),
(9, 55),
(10,70)

DECLARE @TotalCapacity int = (SELECT SUM(Capacity) FROM @Rooms)
DECLARE @AvgCapacity float = (SELECT AVG(Capacity) FROM @Rooms)
DECLARE @RoomsLessThanAvg int = (SELECT COUNT() FROM @Rooms WHERE Capacity < @AvgCapacity)
DECLARE @PercentLessThanAvg float = CAST(@RoomsLessThanAvg * 100.0 / (SELECT COUNT() FROM @Rooms) AS float)

IF @TotalCapacity > 200
BEGIN
PRINT 'Total capacity: ' + CAST(@TotalCapacity AS varchar(10))
PRINT 'Average capacity: ' + CAST(@AvgCapacity AS varchar(10))
PRINT 'Rooms less than average: ' + CAST(@RoomsLessThanAvg AS varchar(10))
PRINT 'Percentage less than average: ' + CAST(@PercentLessThanAvg AS varchar(10)) + '%'
END
ELSE
BEGIN
PRINT 'Total capacity is less than 200: ' + CAST(@TotalCapacity AS varchar(10))
END