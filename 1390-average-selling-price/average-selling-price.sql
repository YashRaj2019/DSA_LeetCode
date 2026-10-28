select p.product_id,
ROUND(
        IFNULL(SUM(us.units * p.price) / sum(us.units) ,0), 2
    ) as average_price

from Prices p
left join UnitsSold us
on p.product_id = us.product_id
AND us.purchase_date BETWEEN p.start_date and p.end_date
group by p.product_id;

