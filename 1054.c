/*************************************************************************
	> File Name: p1054.c
	> Author: 
	> Mail: 
	> Created Time: 2018年10月21日 星期日 16时58分48秒
 ************************************************************************/
//二叉树递归求解表达式
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define INF 0x3f3f3f3f//无穷大

int calc(const char *str, int l, int r, int a_value) {
    int pos = -1, temp_prior = 0, prior = INF - 1;
    for (int i = l; i <= r; i++) {
        int cur_prior = INF;
        switch (str[i]) {
            case '(': temp_prior += 100; break;
            case ')': temp_prior -= 100; break;
            case '+': cur_prior = temp_prior + 1; break;
            case '-': cur_prior = temp_prior + 1; break;
            case '*': cur_prior = temp_prior + 2; break;
            case '/': cur_prior = temp_prior + 2; break;
            case '^': cur_prior = temp_prior + 3; break;
        }
        if (cur_prior <= prior) {
            prior = cur_prior;
            pos = i;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] == 'a') return a_value;
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    } else {
        int a = calc(str, l, pos - 1, a_value);
        int b = calc(str, pos + 1, r, a_value);
        switch (str[pos]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            case '^': return (int)pow(a, b);
        }
    }
    return 0;
}

int main() {
    char str[1000];
    while (scanf("%[^\n]s", str) != EOF) {
        getchar();
        printf("%s = %d\n", str, calc(str, 0, strlen(str) - 1, 3));
    }
    return 0;

}
