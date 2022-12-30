create table DEPARTMENTS (  
  deptno        number,  
  name          varchar2(50) not null,  
  location      varchar2(50),  
  constraint pk_departments primary key (deptno)  
);

create table EMPLOYEES (  
  empno             number,  
  name              varchar2(50) not null,  
  job               varchar2(50),  
  manager           number,  
  hiredate          date,  
  salary            number(7,2),  
  commission        number(7,2),  
  deptno           number,  
  constraint pk_employees primary key (empno),  
  constraint fk_employees_deptno foreign key (deptno) 
      references DEPARTMENTS (deptno)  
);

insert into departments (deptno, name, location) values
   (1, 'Finance','New York');

insert into departments (deptno, name, location) values
   (2, 'Development','San Jose');

insert into EMPLOYEES 
   (empno, name, job, salary, deptno) 
   values
   (1, 'Sam Smith','Programmer', 
    5000, 
  (select deptno 
  from departments 
  where name = 'Development'));

insert into EMPLOYEES 
   (empno, name, job, salary, deptno) 
   values
   (2, 'Mara Martin','Analyst', 
   6000, 
   (select deptno 
   from departments 
   where name = 'Finance'));

insert into EMPLOYEES 
   (empno, name, job, salary, deptno) 
   values
   (3, 'Yun Yates','Analyst', 
   5500, 
   (select deptno 
   from departments 
   where name = 'Development'));

alter table EMPLOYEES 
add country_code varchar2(2);

update employees
set country_code = 'US';

update employees
set commission = 2000
where  name = 'Sam Smith';

delete from employees 
where name = 'Sam Smith';