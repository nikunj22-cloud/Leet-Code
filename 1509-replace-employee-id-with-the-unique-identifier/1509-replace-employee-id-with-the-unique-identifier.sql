# Write your MySQL query statement below
select  EmployeeUNI.unique_id , Employees.name from Employees LEFT JOIN  EmployeeUNI on Employees.id = EmployeeUNI.id;
-- from k bad table 1 likhne ka purpose Table1 ke saare rows rakho
-- Table2 se match mila toh uska data lo, warna null
-- Ab query me FROM Employees kyo likha?

-- Kyunki sabhi Employees ko dikhana compulsory hai (chahe unka unique_id ho ya na ho).

-- Isliye Employees ko main table banaya gaya (FROM Employees).

-- Fir LEFT JOIN lagaya EmployeeUNI pe, taki jinke pass unique_id hai unka aa jaye, warna NULL.