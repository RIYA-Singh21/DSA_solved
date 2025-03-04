# Write your MySQL query statement below
select today.id from weather as today CROSS JOIN weather as yesterday where 
DATEDIFF(today.recordDate,yesterday.recordDate)=1 AND today.temperature>yesterday.temperature;