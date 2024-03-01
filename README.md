найти производную многочлена. Многочлен может быть большой, 
но только с неотрицательными целыми степенями и целыми коэффициентами. 

Вывод должен быть без пробелов и в порядке убывания степеней, 
хотя ввод этому правилу может не удовлетворять. 
Также на ввод может быть подан многочлен с неприведенными слагаемыми.

Для этой задачи существует 10 тестов, созданных вручную (3 из них вы можете увидеть ниже) 
и 90 тестов, созданных автоматически случайным образом.

Sample Input 1:
x^2+x
Sample Output 1:
2*x+1

Sample Input 2:
2*x^100+100*x^2
Sample Output 2:
200*x^99+200*x

Sample Input 3:
x^10000+x+1
Sample Output 3:
10000*x^9999+1

Sample Input 4:
-x^2-x^3
Sample Output 4:
-3*x^2-2*x

Sample Input 5:
x+x+x+x+x+x+x+x+x+x
Sample Output 5:
10
