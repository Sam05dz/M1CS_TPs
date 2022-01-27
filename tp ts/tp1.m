t=-10:.001:10;

subplot(2,3,1);
rect=Heaviside(t+1)-Heaviside(t-1);% rectangle
plot(t,rect,'r'), axis([-3 3,-3 3]),grid
title('Rectangle');

subplot(2,3,2);
r=Heaviside(t).*t; % rampe
plot(t,r,'g'), axis([-5 5,-3 3]),grid
title('Rampe');

subplot(2,3,3); 
tri=tripuls(t/2); %triangle
plot(t,tri), axis([-2 2,-2 2]),grid
title('Triangle');

subplot(2,3,4);
R1=Heaviside(t-1); %exo 3
R2=Heaviside(t-1).*(t-1);
R3=Heaviside(t-2).*t;
R4=trimf(t,[-1 0 1]);%R1+R2-R3;Triangular-shaped built-in
plot(t,R4),axis([-2 2,-2 2]),grid
title('y(t)');
%xlabel('George''s Popularity','fontsize',12,'fontweight','b');
%text(pi,0,' \leftarrow sin(\pi)','FontSize',18);
%txtar =  annotation('textarrow',x,y,'String','We are here.','FontSize',14);

