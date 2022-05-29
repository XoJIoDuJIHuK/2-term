k = 10;
a = 1;
b = 3;
h1 = (b - a) / k;
x1 = a; % x + шаг
x2 = a:h1:b;
T = 0;
m = 2;
while m <= k+1
    T = T + (0.5*h1*(a_func_basa(x1)+a_func_basa(x1+h1)));
    x1 = x1 + h1;
    m = m + 1;
end
tru = 1.39181811116833;
abs_pogr = abs(tru - T);
otn_pogr = abs_pogr / tru * 100;
hgfd = trapz(x2,a_func_basa(x2));