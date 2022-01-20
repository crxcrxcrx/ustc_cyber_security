-- 第一次实验

    -- 1. 无条件查询
        -- 1. 查找pubs库中authors表全部信息
            select * 
                from authors;
                
        -- 2. 查找其他样例表中全部信息: sales, titles, employee, publishers
            select *
                from sales;
                
            select *
                from titles;
                
            select *
                from employee;
                
            select *
                from publishers;
                
    -- 2. 简单条件查询
        -- 1. 查找titles表中全部书号及书名
            select title_id, title
                from  titles;
                
        -- 2. 查找titles表中价格在$10~15元之间的书的书名
            select title
                from titles 
                where price between 10 and 15;
                
        -- 3. 查找titles表中书名以T开头的书号, 书名
            select title_id, title
                from titles
                where title like 'T%';
                
        -- 4. 对authors样例表构造一个简单查询条件进行查询
            -- 查询区号是415开头电话的作者全部信息
            select *
                from authors
                where phone like '415%';
                
    -- 3. 多条件查询
        -- 1. 查找书名起始字符为T, 价格小于$16的书名及价格
            select title, price
                from  titles
                where title like 'T%'
                    and price<16;
                
        -- 2. 查找书名起始字符不为T的, 价格大于$16的书号, 书名及价格
            select title_id, price
                from  titles
                where title not like 'T%'
                    and price>16;
                
        -- 3. 列出已出售书的书号和数量
            select title_id, ytd_sales
                from  titles
                where ytd_sales>0;
                
        -- 4. 对publishers样例表构造一个多条件查询, 进行查询
            -- 查找国家在USA且出版社号以0开头的所有出版商的名字
            select pub_name
                from  publishers
                where country='USA'
                    and pub_id like '0%';
                
    -- 4. 使用函数进行查找
        -- 使用titles表进行查找
        -- 1. 列出有多少种类型的书
            select count(distinct type)
                from titles;
                
        -- 2. 列出书的定价有多少种
            select count(distinct price)
                from titles;
                
        -- 3. 查出书价最高的书价
            select max(price)
                from titles;
                
        -- 4. 列出当年销量的总和
            select sum(ytd_sales)
                from titles;
                
        -- 5. 计算这些书籍的最高书价, 最低书价及平均书价
            select max(price), min(price), avg(price)
                from titles;
                
        -- 6. 按出版社号分组, 列出各个出版社当年销量的总和
            select pub_id, sum(ytd_sales)
                from titles
                group by pub_id;
                
        -- 7. 计算不同的书名共有多少种
            select count(distinct title)
                from titles;
                
        -- 8. 对样例表sales构造一个统计查询, 给出查询结果
            -- 查找发行日期最早的书的发行时间
            select min(ord_date)
                from sales;
                
    -- 5. 得到排序的查询结果
        -- 1. 查找作者的姓, 名, 电话号码, 并按作者姓, 名排列
            select au_lname, au_fname, phone
                from authors
                order by au_lname, au_fname;
                
        -- 2. 查找书名和书的价格, 按书价由大到小的次序排列
            select title, price
                from titles
                order by price desc;
                
        -- 3. 列出烹调书, 它们数量和该类的平均价格
            select count(distinct type), avg(price)
                from titles
                where type like '%cook%';
                
        -- 4. 对其他样例表构造查询条件, 排序要求, 给出查询结果
            -- 升序排列employee的emp_id并输出全部信息
            select *
                from employee
                order by emp_id ;
                
    -- 6. 用嵌套或连接进行查询
        -- 1. 使用样例表titles, publishers查找出版社的名称以及所出的书名
            select pub_name, title 
                from titles, publishers
                where titles.pub_id=publishers.pub_id;
                
        -- 2. 使用样例表authors, titleauthor, titles查找作者的姓、名和所写的书名
            select au_lname,au_fname,title 
                from authors, titleauthor, titles
                where authors.au_id=titleauthor.au_id 
                    and titleauthor.title_id=titles.title_id;
            
        -- 3. 从titles, sales中找出定单量最大的那一行定单的书的书名, 价格, 定单量
            select title,price,qty
                from titles, sales
                where titles.title_id=sales.title_id
                    and qty=
            (
            select max(qty)
                from  sales
            )

        -- 4. 构造其他条件, 在sales和stores样例表中进行连接或嵌套查询
            -- 对每个书店以销售数量为关键字降序排序书店编号, 书店名称和销售总数量
            select stor_id, sum(qty) qty_sum
                into #temp
                from sales
                group by stor_id;
                
            select stores.stor_id, stores.stor_name, qty_sum
                from stores, #temp
                where stores.stor_id=#temp.stor_id
                order by qty_sum desc;
                
            drop table #temp;
-- 第二次实验

    -- 1. 手动建表
        -- 1. 先建立一个表T的前五个属性以及另一个表S
        create table TPB18061383
        (
        书名 char(50),
        作者 char(20),
        书号 char(10),
        价格 numeric(5,2),
        出版社 char(20)
        );
        
        create table SPB18061383
        (
        书号 char(10),
        页数 smallint,
        库存量 smallint,
        仓库号 smallint
        );
    
    -- 2. 手动添加T最后一个属性
        alter table TPB18061383
        add 出版时间 numeric(4);

        -- 3. 依次插入T和S的数据
        insert into TPB18061383
            values
            (
            '计算机原理',
            '张一平',
            'S3092',
            '20.80',
            '中国科技大学',
            1986
        );
        
        insert into TPB18061383
            values
            (
            'C语言程序设计',
            '李华',
            'H1298',
            '15.30',
            '电子工业',
            1993
        );
        
        insert into TPB18061383
            values
            (
            '数据库原理',
            '王家树',
            'D1007',
            '22.70',
            '高等教育',
            1987
        );

        insert into TPB18061383
            values
            (
            '计算机网络',
            '高明',
            'S5690',
            '18.90',
            '高等教育',
            1993
        )

        insert into TPB18061383
            values
            (
            'Artificial intelligence',
            'P.Winston',
            'D2008',
            '20.50',
            '电子工业',
            1989
        );
        
        insert into TPB18061383
            values
            (
            'Expert systems',
            'R.Ullman',
            'H3067',
            '17.00',
            '清华大学',
            1994
        );
        
        insert into TPB18061383
        values
        (
            '软件工程',
            '鲁廷璋',
            'S2005',
            '35.00',
            '中国科技大学',
            1995
        );
        
        insert into TPB18061383
            values
            (
            'Fortran程序设计',
            '顾学峰',
            'S5006',
            '18.00',
            '高等教育',
            1995
        );
        
        insert into SPB18061383
        values
        (
            'S3092',
            304,
            300,
            1
        );

        insert into SPB18061383 
        values
        (
            'D1007',
            280,
            200,
            3
        );

        insert into SPB18061383
        values
        (
            'S5006',
            315,
            240,
            2
        );

        insert into SPB18061383
        values
        (
            'S5690',
            300,
            300,
            2
        );

        insert into SPB18061383
        values
        (
            'H1298',
            210,
            470,
            5
        );

        insert into SPB18061383
        values
        (
            'D2008',
            358,
            342,
            2
        );

        insert into SPB18061383
        values
        (
            'S2005',
            298,
            200,
            2
        );

        insert into SPB18061383
        values
        (
            'H3067',
            307,
            510,
            1
        );
            
    -- 2. 用子查询方式建表ST
        select 书名,价格
            into STPB18061383
            from TPB18061383;
            
    -- 3. 按书号建索引IT
        create index ITPB18061383
            on TPB18061383
            (
            书号
        );
            
    -- 4. 用子查询方式建视图VT, 并查找相应信息
        -- 最高价格的书名
        create view VTPB18061383 
        (
        最高价格的书名
    )
        as select 书名
        from TPB18061383
        where 价格=
        (
            select max(价格)
            from TPB18061383
        );
            
    -- 5. 删除ST表
        drop table STPB18061383;
        
    -- 6. 删除VT视图
        drop view VTPB18061383;
        
    -- 7. 删除IT索引
        drop index TPB18061383.ITPB18061383;
        
    -- 8. 对T和S建索引与视图各一个
        -- 对T按书名建立索引IT
        create index ITPB18061383
            on TPB18061383
            (
            书名
        );
        
        -- 对T建立书名和出版社视图VT
        create view VTPB18061383 
        (
        书名,
        出版社
    )
        as select 书名, 出版社
            from TPB18061383;
            
        -- 对S按书号建立索引IS
        create index ISPB18061383
            on SPB18061383
            (
            书号
        );
        
        -- 对S建立书号和仓库号视图VS
        create view VTPB18061383 
        (
        书号,
        仓库号
    )
        as select 书号, 仓库号
                from SPB18061383;

-- 第三次实验

    -- 1. 在 T** 表中插入一元组, Digital Image Processing, S7028, 36.00
        insert into TPB18061383
        (
        书名,
        书号,
        价格
    )
        values
        (
        'Digital Image Processing',
        'S7028',
        '36.00'
        );
        
    -- 2. 删除书名为Fortran程序设计的那个元组
        delete from TPB18061383
            where 书名='Fortran程序设计';
            
    -- 3. 删除书号以H开头的元组
        delete from TPB18061383
            where 书号 like 'H%';
            
    -- 4. 把书价调整到原来价格的90%
        update TPB18061383
            set 价格=价格*0.9;
            
    -- 5. 把书号以D开头的那些书的书价减掉2.00元
        update TPB18061383
            set 价格=价格-2
            where 书号 like 'D%';
            
    -- 6. 将计算机原理的书号改为S1135
        update TPB18061383
            set 书号='S1135'
            where 书名='计算机原理';
            
    -- 7. 对所建的表, 进行其他插入, 删除, 更新操作各一个
        -- 插入书籍网络空间安全大礼包, 作者麻治昊, 价格1.00, 出版社gitee.com/yssickjgd
        insert into TPB18061383
        (
        书名,
        作者,
        价格,
        出版社
    )
            values
            (
        '网络空间安全大礼包',
        '麻治昊',
        '1.00',
        'gitee.com/yssickjgd'
        );
        
        -- 删除所有高等教育出版社的书
        delete from TPB18061383
            where 出版社='高等教育';
            
        -- 更新所有价格不小于15元的书籍为半价
        update TPB18061383
            set 价格=价格*0.5
            where 价格>=15;
            
    -- 8. 建立gpa映射关系
        -- 输入参数为百分制成绩, 返回绩点, 等级成绩
        -- 输入成绩不在0到100存储过程返回-1, 否则返回0
        -- 声明过程
        create procedure PB18061383
            @fz int,
            @jd varchar(5) output,
            @djcj varchar(5) output
            as begin
                if @fz<0
                    or @fz>100
                    return -1
                select @jd=jd,@djcj=djcj
            from pubs..cjdzb
            where ceiling(@fz)>=startfz
            and ceiling(@fz)<=endfz
                return 0
            end;
        
        -- 执行过程
        declare @jd varchar(5), @djcj varchar(5);
        execute PB18061383 83.4, @jd output, @djcj output;
        select @jd jd, @djcj djcj;