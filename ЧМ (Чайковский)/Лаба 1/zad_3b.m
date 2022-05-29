a = 1;
b = 3;
N = 100;
h = (b-a)/N;
x = a;
sum = 0;
for k = 0: 1: 100
    if (k == 0) || (k == 100)
        sum = sum + func_1(x);
    elseif mod(k,2) == 0
        sum = sum + 2 * func_1(x);
    elseif mod(k,2) ~= 0
        sum = sum + 4 * func_1(x);
    end
    x = x + h;
end
sum = sum * h / 3;