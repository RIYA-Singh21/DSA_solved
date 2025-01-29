# Write your MySQL query statement below
select product.product_name,  year,price from sales left join product on product.product_id=sales.product_id;