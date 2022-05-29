tru = 743.813911923866;
k = 100;
a = 1;
b = 3;
h1 = (b - a) / k;
x1 = a; % x + шаг

y1 = exp(4*x1-3)/x1; % функция при делении на 100 частей
T = 0;
m = 2;
while m <= k+1
    T = T + (0.5*h1*(func_basa(x1)+func_basa(x1+h1)));
    x1 = x1 + h1;
    m = m + 1;
end
abs_pogr = abs(tru - T);
otn_pogr = abs_pogr / tru * 100;