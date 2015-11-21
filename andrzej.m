x_1=[6;3;1];
x_2=[3;2;2];
x_3=[2;0;3];

X=[x_1,x_2,x_3];
n=3;
t = 1:n;
ti = 0:0.1:n;
xi = interp1(t, X(1,:), ti, "spline"); 
yi = interp1(t, X(2,:), ti, "spline"); 
zi = interp1(t, X(3,:), ti, "spline"); 
Xi = [xi; yi; zi];
hold on;
plot(xi,yi,'bx')

