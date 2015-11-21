x_1=[15;8;10];
x_2=[12;15;14];
x_3=[5;18;17];
x_4=[10;7;20];
x_5=[13;9;25];
X=[x_1,x_2,x_3,x_4,x_5];
n=5;
t = 1:n;
ti = 0:0.1:n;
xi = interp1(t, X(1,:), ti, "spline"); 
yi = interp1(t, X(2,:), ti, "spline"); 
zi = interp1(t, X(3,:), ti, "spline"); 
Xi = [xi; yi; zi];
plot3(xi,yi,zi)
Xb = Xi';
dlmwrite('/home/hodor/numeryczne/MojeMatrix/z7/Szablony/prj/daneLotu.txt',Xi)
dlmwrite('/home/hodor/numeryczne/MojeMatrix/z7/Szablony/prj/daneLotuTranspose.txt',Xb)
