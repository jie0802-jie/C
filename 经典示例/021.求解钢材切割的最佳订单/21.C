#include <stdio.h>
#include <stdlib.h>

#define N 20

int bestlen;
int bestsele[N];
int sele[N];
int n;
int orderlen[N];
int total;
int DELTA;

void backtrack() {  // 改名为 backtrack
    int i, len = 0, count = 0;
    for (i = 0; i < n; i++) {
        if (sele[i]) {
            len += orderlen[i];
            count++;
        }
    }
    if (count > 0) len += (count - 1) * DELTA;

    if (len <= total) {
        if (bestlen < len) {
            bestlen = len;
            for (i = 0; i < n; i++) bestsele[i] = sele[i];
        }
        for (i = 0; i < n; i++) {
            if (!sele[i]) {
                sele[i] = 1;
                backtrack();  // 递归调用
                sele[i] = 0;
            }
        }
    }
}

int main() {
    system("cls");
    printf("Enter total length of the steel: ");
    scanf("%d", &total);
    if (total <= 0) { printf("Invalid length!\n"); return 1; }

    printf("Enter number of orders (max %d): ", N);
    scanf("%d", &n);
    if (n <= 0 || n > N) { printf("Invalid order count!\n"); return 1; }

    printf("Enter cutting loss (DELTA): ");
    scanf("%d", &DELTA);

    printf("Enter the orders:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &orderlen[i]);
        if (orderlen[i] <= 0) { printf("Invalid order length!\n"); return 1; }
    }

    bestlen = 0;
    for (int i = 0; i < n; i++) sele[i] = bestsele[i] = 0;

    backtrack();  // 调用改名后的函数

    printf("\nSelected orders:\n");
    for (int i = 0; i < n; i++) {
        if (bestsele[i]) printf("Order %d: length = %d\n", i + 1, orderlen[i]);
    }
    printf("\nTotal used length: %d (%.2f%% utilization)\n", bestlen, (float)bestlen / total * 100);

    printf("\nPress Enter to quit...");
    getchar(); getchar();
    return 0;
}
