
select
    [Prices].[product_id] as [product_id],
    ISNULL(ROUND(sum(CONVERT(float, units*price))/sum(units), 2), 0) as average_price
FROM
    [Prices]
LEFT JOIN [UnitsSold] ON [UnitsSold].[purchase_date] BETWEEN [Prices].[start_date] AND [Prices].[end_date]
AND [Prices].[product_id] = [UnitsSold].[product_id] 
GROUP BY [Prices].[product_id];
