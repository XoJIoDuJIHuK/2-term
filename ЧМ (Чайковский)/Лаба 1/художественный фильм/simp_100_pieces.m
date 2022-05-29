tru = 743.813911923866;
k = 100;
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
    Sn1 = Sn1 + 4*func_basa(a+r*h);
    r = r + 2;
end
while m < k
    Sch1 = Sch1 + 2*func_basa(a+m*h);
    m = m + 2;
end
S = h/3 * (func_basa(a)+ Sch1 + Sn1 + func_basa(b));
abs_pogr = abs(tru - S);
otn_pogr = abs_pogr / tru * 100;