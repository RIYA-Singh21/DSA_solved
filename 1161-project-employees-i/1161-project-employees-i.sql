# Write your MySQL query statement below
select p.project_id, ROUND(AVG(e.experience_years),2) as average_years from project p LEFT JOIN employee e on
p.employee_id=e.employee_id group by p.project_id;