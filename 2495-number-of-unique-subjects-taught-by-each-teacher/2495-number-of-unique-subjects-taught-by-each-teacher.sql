# Write your MySQL query statement below
select t1.teacher_id,count(distinct t1.subject_id) as cnt from Teacher t1 left join Teacher t2 on t1.teacher_id =t2.teacher_id group by t1.teacher_id