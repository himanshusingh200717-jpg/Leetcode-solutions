# Write your MySQL query statement below
select e.name,B.bonus from employee e
left join Bonus b
on e.empid=b.empid
where bonus<1000 or bonus is null