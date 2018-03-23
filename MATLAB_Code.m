%% Arduino Group Project: Bye Felicia!
% This code will connect to an Arduino over a Serial Port.
% It will plot the light relay information after an hour. 
 
%% Clear command window & workspace variables, close all open windows
 
clc;                     % clears the command line
clear;                   % clears the variable workspace
close all;               % closes all open windows
delete(instrfindall);    % deletes any connected ports
 
%% Set up serial port and ensure it outputs data
 
port = serial('COM4','BaudRate',9600);        % Creates a serial connection through COM4
fopen(port);                                  % opens the serial port
pause(1);                                     % pause() for 1 second to make sure a connection is made
out = instrfind('port',port);                 % see if the port you specified is open
disp('Serial Port is Open');                  % displays that the port is open in command window
 
g = []                    % initial matrix g
tic                       % start stopwatch 
 
% use while loop to plot information as it comes in from serial port for one hour 
 
while toc <= 3600              % run loop for 3600 seconds(or one hour)               
    a = fscanf(port);          % reads data sent in from Arduino, assign it to variable a
    a_num = str2num(a);        % converts a, a string, to a number
    g(end+1) = a_num ;         % add each new a value to the end of matrix g
end
 
% build histogram graph
    
figure(1)     ;                               % start new figure window
edges = [0 100 100 400 400 800 800 1023] ;    % set edges for the four bins
histogram(g,edges)               ;            % plot data
title('Number of Lights On vs Time') ;        % title plot
ylabel('Time (s x2)')           ;             % label y axis
y = xlabel('Number of Lights On     ') ;      % label x axis
titlepos = get(y, 'position')    ;            % retrieves the position of the x label on figure in a 1 x 3 matrix
titlepos(2) = -0.3 ;                          % change second number in position matrix to -0.3
set(y, 'position', titlepos);                 % sets new position of x label 
xlim([0 1023]);                               % set x axis limits
xticks([])   ;                                % removes numbers from x axis
text(30,-0.12,'None') ;                       % add text below first bin indicating amount of lights on
text(250,-0.12,'One') ;                       % add text below second bin indicating amount of lights on
text(575,-0.12,'Two')  ;                      % add text below third bin indicating amount of lights on
text(900,-0.12,'Three');                      % add text below fourth bin indicating amount of lights on
 
%% Close the serial port
 
fclose(port);
delete(port)
clear a;
disp('Serial Port is closed')    % display the port is closed to user
