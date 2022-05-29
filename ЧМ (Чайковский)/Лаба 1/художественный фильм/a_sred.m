a = 1;
b = 3;
N = 10;
h = (b-a)/N;
x = a + 0.5 * h;
sum = 0;
for k = 0: 1: N - 1
    sum = sum + a_func_basa(x);
    x = x + h;
end
sum = sum * h;
tru = 1.39181811116833;
abs_pogr = abs(tru - sum);
otn_pogr = abs_pogr / tru * 100;