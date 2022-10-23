-- Buat query untuk menampilkan nama departemen dari tiap departemen yang
-- memiliki total gaji diatas 1/8 dari total gaji keseluruhan pada perusahaan. Gunakan
-- klausa WITH untuk menulis query tersebut. Beri nama SUMMARY

WITH SUMMARY AS (
    SELECT
        d.department_name,
        SUM(e.salary) AS total_gaji
    FROM
        departments d
    JOIN
        employees e ON d.department_id = e.department_id
    GROUP BY
        d.department_name
)
SELECT
    department_name
FROM
    SUMMARY
WHERE
    total_gaji > (SELECT SUM(salary) FROM employees) / 8;
