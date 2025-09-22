x = -2*pi : 0.1 : 2*pi;
y = sin(x);
figure;

subplot(2,2,1);
plot(x,y,'b-','LineWidth',1.5);
title("Do thi ban dau");
xlabel("x");
ylabel("sin(x)");
grid on;

%(2) axis
subplot(2,2,2);
plot(x,y,'b--','LineWidth',1.5);
axis([0 pi 0 1]);
title('Gioi han truc axis');
xlabel('x'); ylabel('sin(x)');

% (3) axis equal
subplot(2,2,3);
plot(x,y,'g-','LineWidth',1.5);
axis equal;         % tỷ lệ đơn vị x,y bằng nhau
title('axis equal');
grid on;

% (4) axis square
subplot(2,2,4);
plot(x,y,'m-','LineWidth',1.5);
axis square;        % khung hình vuông
title('axis square');
grid on;
