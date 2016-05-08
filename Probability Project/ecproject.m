% Simulates 3 four-sided dice and sums the three values
% Calculates and plots probability/cumulative distribution functions 
% of each possible sum
clear all;
close all;

% Using seed and x number of trials
rng(1738);
x = 100000;

% Populate array with x trials of 3 rolls ea
test = randi([1 4],[x 3]);

% Sum of each roll
sums = sum(test, 2);

% Calc PDF of sum value = 3 to 12
pdfx = zeros(10,1);
pdfx(1) = x*(1/64);
pdfx(2) = x*(3/64);
pdfx(3) = x*(6/64);
pdfx(4) = x*(10/64);
pdfx(5) = x*(12/64);
pdfx(6) = x*(12/64);
pdfx(7) = x*(10/64);
pdfx(8) = x*(6/64);
pdfx(9) = x*(3/64);
pdfx(10) = x*(1/64);

cdfx = zeros(10,1);
cdfx(1) = pdfx(1)/x;
for i=2:10
    cdfx(i) = cdfx(i-1) + (pdfx(i)/2500);
end

%% Plotting Calc. PDF Graph %%
figure
subplot(1,2, 1);
bar(pdfx)
hold on
plot(pdfx, '--*r')
hold off
title('PDF of Calculated Values');
xlabel('Sum Value');
ylabel('Frequency');
set(gca,'XTickLabel',{3:12})
%% Plotting Exp. PDF Graph %%

% Tested out histogram, but not all version of Matlab have it
%figure
%histogram(sums)
%title('Simulated PDF of Sum Values')
%xlabel('Sum Value');
%ylabel('Frequency');

[countsA, binsA] = hist(sums);
cdfA = cumsum(countsA) / sum(countsA);

subplot(1,2, 2);
bar(binsA, countsA,'y');
hold on
plot(binsA, countsA,'--*r')
hold off
title('PDF of Simulated Values')
xlabel('Sum Value');
ylabel('Frequency');
%% Plotting Calc. CDF Graph
figure
subplot(1,2, 1);
bar(cdfx)
hold on
plot(cdfx,'--*r')
hold off
title('CDF of Calculated Values')
xlabel('Sum Value');
ylabel('Total Probability');
set(gca,'XTickLabel',{3:12})
%% Plotting Exp. CDF Graph
subplot(1,2, 2);
bar(binsA, cdfA,'y');
hold on
plot(binsA, cdfA,'--*r');
hold off
title('CDF of Simulated Values');
xlabel('Sum Value');
ylabel('Total Probability');