k = 10;
a = 1;
b = 3;
h = (b - a) / k; % шаг
x = a; %  х + шаг
m = 2;
r = 1;
Sn1 = 0; % сумма нечетных элементов 
Sch1 = 0; % сумма четных элементов
S = 0;
while r < k
    Sn1 = Sn1 + 4*a_func_basa(a+r*h);
    r = r + 2;
end
while m < k
    Sch1 = Sch1 + 2*a_func_basa(a+m*h);
    m = m + 2;
end
S = h/3 * (a_func_basa(a)+ Sch1 + Sn1 + a_func_basa(b));
tru = 1.39181811116833;
abs_pogr = abs(tru - S);
otn_pogr = abs_pogr / tru * 100;
x2 = a:h:b;
iuytrew = quad(@a_func_basa,a,b,h^4/180);