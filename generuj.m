y=0:0.01:10;
for x=0:0.01:10
	b=ones(1,1001)*x;
z=cos(x)*sin(y);
hold on;
plot3(b,y,z);
end;
