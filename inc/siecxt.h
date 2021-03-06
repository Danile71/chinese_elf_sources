#ifndef _SIECXT_H_
 #define _SIECXT_H_ 
static const char PNT_ONE[]="%t";
static const char PST_ONE[]="%s";
static const char PST_TWO[]="%s%s";
static const char PNT_TWO[]="%t%t";
static const char PST_4[]="%s%s%s%s";
static const char PST_3[]="%s%s%s";
static const char PNT_YMD[]="%04d%t%02d%t%02d%t";
//定义二十节气初始数据(此数据为51年)
#define LHYear  2050//定义计算节气最大年份2050
#define LLYear  1990//定义计算节气最小年份1901
#define LCData (LHYear-LLYear+1)*12//节气数据长度
static const char cwName[][7][10]={{"MONDAY","TUESDAY","WEDNESDAY","THUSDAY","FRIDAY","SATURDAY","SUNDAY"},
                                   {"MON","TUES","WED","THU","FRI","SAT","SUN"},
                                   {"Monday","Tuesday","Wednesday","Thusday","Friday","Saturday","Sunday"},
                                   {"Mon","Tues","Wed","Thu","Fri","Sat","Sun"},
                                   {"星期一","星期二","星期三","星期四","星期五","星期六","星期日"},
                                   {"一","二","三","四","五","六","日"}};
static const unsigned short MonthSum[12]={0,31,59,90,120,151,181,212,243,273,304,334};
static const unsigned long wLunar[100]={0x00A4B,0x5164B,0x006A5,0x006D4,0x415B5,0x002B6,0x00957,0x2092F,0x00497,0x60C96,
/*农历数据*/                            0x00D4A,0x00EA5,0x50DA9,0x005AD,0x002B6,0x3126E,0x0092E,0x7192D,0x00C95,0x00D4A,
                                        0x61B4A,0x00B55,0x0056A,0x4155B,0x0025D,0x0092D,0x2192B,0x00A95,0x71695,0x006CA,
                                        0x00B55,0x50AB5,0x004DA,0x00A5B,0x30A57,0x0052B,0x8152A,0x00E95,0x006AA,0x615AA,
                                        0x00AB5,0x004B6,0x414AE,0x00A57,0x00526,0x31D26,0x00D95,0x70B55,0x0056A,0x0096D,
                                        0x5095D,0x004AD,0x00A4D,0x41A4D,0x00D25,0x81AA5,0x00B54,0x00B6A,0x612DA,0x0095B,
                                        0x0049B,0x41497,0x00A4B,0xA164B,0x006A5,0x006D4,0x615B4,0x00AB6,0x00957,0x5092F,
                                        0x00497,0x0064B,0x30D4A,0x00EA5,0x80D65,0x005AC,0x00AB6,0x5126D,0x0092E,0x00C96,
                                        0x41A95,0x00D4A,0x00DA5,0x20B55,0x0056A,0x7155B,0x0025D,0x0092D,0x5192B,0x00A95,
                                        0x00B4A,0x416AA,0x00AD5,0x90AB5,0x004BA,0x00A5B,0x60A57,0x0052B,0x00A93,0x40E95};
static const char WeekGB[][7]={"星期一","星期二","星期三","星期四","星期五","星期六","星期日"};//一二三四五六日
static const char WeekID[][3]={"一","二","三","四","五","六","日"};//一二三四五六日
static const char WeekHD[]={"星期"};//星期
static const char cTGan[][3]={"甲","乙","丙","丁","戊","己","庚","辛","壬","癸"};/*天干名称*/
static const char cDZhi[][3]={"子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥"};/*地支名称*/
static const char cSXin[][3]={"鼠","牛","虎","兔","龙","蛇","马","羊","猴","鸡","狗","猪"};/*属相名称*/
static const char sTerm[][5]={"小寒","大寒","立春","雨水","惊蛰","春分","清明","谷雨",
                              "立夏","小满","芒种","夏至","小暑","大暑","立秋","处暑",
                              "白露","秋分","寒露","霜降","立冬","小雪","大雪","冬至"};
/*农历日期名:初一...三十*/
static const char cnNum[][3]={"一","二","三","四","五","六","七","八","九","十"};
static const char cnShi[][3]={"初","十","廿","三"};
static const char cnMth[][3]={"正","二","三","四","五","六","七","八","九","十","冬","腊"};/*农历月份名*/
static const char cnStr[][3]={"年","月","日","时","闰","农","历"};/*其它名称:年,月,闰*/
//定义二十四节气数据表
static const unsigned char HolDay[LCData]={
/*
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1901
0x96,0xA4,0x96,0x96,0x97,0x87,0x79,0x79,0x79,0x69,0x78,0x78,//1902
0x96,0xA5,0x87,0x96,0x87,0x87,0x79,0x69,0x69,0x69,0x78,0x78,//1903
0x86,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x78,0x87,//1904
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1905
0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,//1906
0x96,0xA5,0x87,0x96,0x87,0x87,0x79,0x69,0x69,0x69,0x78,0x78,//1907
0x86,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1908
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1909
0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,//1910
0x96,0xA5,0x87,0x96,0x87,0x87,0x79,0x69,0x69,0x69,0x78,0x78,//1911
0x86,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1912
0x95,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1913
0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,//1914
0x96,0xA5,0x97,0x96,0x97,0x87,0x79,0x79,0x69,0x69,0x78,0x78,//1915
0x96,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//1916
0x95,0xB4,0x96,0xA6,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x87,//1917
0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x77,//1918
0x96,0xA5,0x97,0x96,0x97,0x87,0x79,0x79,0x69,0x69,0x78,0x78,//1919
0x96,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//1920
0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x87,//1921
0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x77,//1922
0x96,0xA4,0x96,0x96,0x97,0x87,0x79,0x79,0x69,0x69,0x78,0x78,//1923
0x96,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//1924
0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x87,//1925
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1926
0x96,0xA4,0x96,0x96,0x97,0x87,0x79,0x79,0x79,0x69,0x78,0x78,//1927
0x96,0xA5,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1928
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//1929
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1930
0x96,0xA4,0x96,0x96,0x97,0x87,0x79,0x79,0x79,0x69,0x78,0x78,//1931
0x96,0xA5,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1932
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1933
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1934
0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,//1935
0x96,0xA5,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1936
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1937
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1938
0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,//1939
0x96,0xA5,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1940
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1941
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1942
0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,//1943
0x96,0xA5,0x96,0xA5,0xA6,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1944
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//1945
0x95,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x78,0x69,0x78,0x77,//1946
0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,//1947
0x96,0xA5,0xA6,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//1948
0xA5,0xB4,0x96,0xA5,0x96,0x97,0x88,0x79,0x78,0x79,0x77,0x87,//1949
0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x77,//1950
0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,//1951
0x96,0xA5,0xA6,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//1952
0xA5,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//1953
0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x68,0x78,0x87,//1954
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1955
0x96,0xA5,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//1956
0xA5,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//1957
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1958
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1959
0x96,0xA4,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,//1960
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1961
0x96,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1962
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1963
0x96,0xA4,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,//1964
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1965
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1966
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1967
0x96,0xA4,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//1968
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1969
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1970
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,//1971
0x96,0xA4,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//1972
0xA5,0xB5,0x96,0xA5,0xA6,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1973
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1974
0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x78,0x69,0x78,0x77,//1975
0x96,0xA4,0xA5,0xB5,0xA6,0xA6,0x88,0x89,0x88,0x78,0x87,0x87,//1976
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//1977
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x78,0x87,//1978
0x96,0xB4,0x96,0xA6,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x77,//1979
0x96,0xA4,0xA5,0xB5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//1980
0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x77,0x87,//1981
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//1982
0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x77,//1983
0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x87,//1984
0xA5,0xB4,0xA6,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//1985
0xA5,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//1986
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x79,0x78,0x69,0x78,0x87,//1987
0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,//1988
0xA5,0xB4,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,//1989
*/
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x79,0x77,0x87,//1990
0x95,0xB4,0x96,0xA5,0x86,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1991
0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,//1992
0xA5,0xB3,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,//1993
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1994
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x76,0x78,0x69,0x78,0x87,//1995
0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,//1996
0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//1997
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//1998
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//1999
0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,//2000
0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//2001
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//2002
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//2003
0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,//2004
0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//2005
0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//2006
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,//2007
0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,//2008
0xA5,0xB3,0xA5,0xB5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//2009
0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//2010
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x78,0x87,//2011
0x96,0xB4,0xA5,0xB5,0xA5,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,//2012
0xA5,0xB3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x87,//2013
0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//2014
0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,//2015
0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,//2016
0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x87,//2017
0xA5,0xB4,0xA6,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//2018
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x79,0x77,0x87,//2019
0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x86,//2020
0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,//2021
0xA5,0xB4,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,//2022
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x79,0x77,0x87,//2023
0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,//2024
0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,//2025
0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//2026
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//2027
0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,//2028
0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,//2029
0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//2030
0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,//2031
0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,//2032
0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x86,//2033
0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x78,0x88,0x78,0x87,0x87,//2034
0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//2035
0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,//2036
0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,//2037
0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//2038
0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//2039
0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,//2040
0xA5,0xC3,0xA5,0xB5,0xA5,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,//2041
0xA5,0xB3,0xA5,0xB5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,//2042
0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//2043
0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x88,0x87,0x96,//2044
0xA5,0xC3,0xA5,0xB4,0xA5,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,//2045
0xA5,0xB3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x87,//2046
0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,//2047
0x95,0xB4,0xA5,0xB4,0xA5,0xA5,0x97,0x87,0x87,0x88,0x86,0x96,//2048
0xA4,0xC3,0xA5,0xA5,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x86,//2049
0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x78,0x78,0x87,0x87}; //2050
static const unsigned char sGId[12][5]={
  {3,5,7,9,1},//腊月 小寒 1月
  {2,4,6,8,0},//正月 立春 2月
  {3,5,7,9,1},//二月 惊蛰 3月
  {4,6,8,0,2},//三月 清明 4月
  {5,7,9,1,3},//四月 立夏 5月
  {6,8,0,2,4},//五月 芒种 6月
  {7,9,1,3,5},//六月 小署 7月
  {8,0,2,4,6},//七月 立秋 8月
  {9,1,3,5,7},//八月 白露 9月
  {0,2,4,6,8},//九月 寒露 10月
  {1,3,5,7,9},//十月 立冬 11月
  {2,4,6,8,0} //冬月 大雪 12月
};                                   //1 2 3 4 5 6 7 8 9 10 1112
static const unsigned char sZId[12]={1,2,3,4,5,6,7,8,9,10,11,0};
#endif
