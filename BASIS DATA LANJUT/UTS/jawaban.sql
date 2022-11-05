-- Emp(eid:integer, ename : string, age : integer, salary: real)
-- Works(eid:integer, did:integer, pct_time: integer)
-- Dept(did:integer, dname: string, budget: real, managerid: integer

-- tampilkan karyawan yang bekerja di departemen IT
SELECT ename
FROM Emp
WHERE eid IN (SELECT eid
              FROM Works
              WHERE did IN (SELECT did
                            FROM Dept
                            WHERE dname = 'IT'));

-- tampilkan karyawan yang bekerja di departemen IT dan memiliki usia yang lebih dari usia rata-rata orang-orang yang bekerja di departemen IT
SELECT ename
FROM Emp
WHERE eid IN (SELECT eid
              FROM Works
              WHERE did IN (SELECT did
                            FROM Dept
                            WHERE dname = 'IT'))
AND age > (SELECT AVG(age)
              FROM Emp
              WHERE eid IN (SELECT eid
                             FROM Works
                             WHERE did IN (SELECT did
                                        FROM Dept
                                        WHERE dname = 'IT')));

-- Matakuliah(kodemk,namamk,sks) = berisi daftar matakuliah yang ditawarkan. Dosen(nip,nama) = daftar dosen pengampu matakuliah
-- Mahasiswa(nim,nama,dosenpembimbing) = daftar mahasisw
-- Kuliah(kodekuliah,kodemk,nip,thnakademik,semester) = daftar matakuliah dan dosen pengampu.
-- Peserta(nim,kodekuliah,nilai) = nilai mahasiswa dalam ‘a’, ‘b’s.d
-- seorang dosen bisa mengajar matakuliah yang sama untuk kelas yang berbeda pada suatu semester. Semester bernilai '1' untuk ganjil atau '2' untuk genap. Thn akademik dinyatakan dalam format
-- panjang seperti '2007-2008'

-- Tampilkan banyaknya SKS yang telah diselesaikan oleh masing-masing mahasiswa
SELECT nim, nama, SUM(sks) AS sks
FROM Mahasiswa, Matakuliah, Kuliah, Peserta
WHERE Mahasiswa.nim = Peserta.nim
AND Matakuliah.kodemk = Kuliah.kodemk
AND Peserta.kodekuliah = Kuliah.kodekuliah
GROUP BY nim, nama;

-- Tampilkan dosen yang pernah mengampu kelas matakuliah yang pesertanya tidak lebih dari 15
-- mahasiswa
SELECT DISTINCT nip, nama
FROM Dosen, Kuliah, Peserta
WHERE Dosen.nip = Kuliah.nip
AND Kuliah.kodekuliah = Peserta.kodekuliah
AND (SELECT COUNT(nim)
     FROM Peserta
     WHERE kodekuliah = Kuliah.kodekuliah) <= 15;

-- Buat penyataan SQL untuk menemukan semua email duplikat dalam tabel email diatas
-- Table: email
-- Column: id, email
SELECT email
FROM email
GROUP BY email
HAVING COUNT(email) > 1;

-- Tulis queri SQL untuk menemukan karyawan yang memiliki gaji tertinggi di setiap departemen
SELECT Name, Salary
FROM Gaji as g1
WHERE Salary >= ALL (SELECT Salary
                     FROM Gaji as g2
                     WHERE g1.DepartmentId = g2.DepartmentId);
