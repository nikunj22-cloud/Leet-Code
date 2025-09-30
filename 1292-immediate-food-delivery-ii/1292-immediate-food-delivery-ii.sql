# Write your MySQL query statement below
-- SQL me ya logic me “first order” identify karne ka sahi tarika hai order_date (earliest date per customer).

-- Earliest order_date = first order
-- customer id 3 wala imeediate joiner ni h kyoki uska woh second order h jisme woh imediate joiner bn rha h or hmko first order k liye nikalana h 
select round(avg(order_date = customer_pref_delivery_date)*100 , 2)as immediate_percentage from Delivery where( customer_id , order_date) in ( select customer_id , min(order_date) from delivery group by customer_id);

