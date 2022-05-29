tru = 743.813911923866;
a = 1;
b = 3;
N = 100;
h = (b-a)/N;
x = a;
sum = 0;
for k = 0: 1: 100
    sum = sum + func_basa((2 * x - h) / 2);
    x = x + h;
end
sum = sum * h;
abs_pogr = abs(tru - sum);
otn_pogr = abs_pogr / tru * 100;