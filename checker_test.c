#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	*g_a, *g_b, g_na, g_nb;

static void swap_top(int *s, int n) {
	int t;
	if (n >= 2) { t = s[0]; s[0] = s[1]; s[1] = t; }
}
static void rotate(int *s, int n) {
	int t, i;
	if (n > 1) { t = s[0]; for(i=0;i<n-1;i++) s[i]=s[i+1]; s[n-1]=t; }
}
static void rev_rotate(int *s, int n) {
	int t, i;
	if (n > 1) { t = s[n-1]; for(i=n-1;i>0;i--) s[i]=s[i-1]; s[0]=t; }
}
static void push_ab(void) {
	int i;
	if (g_nb > 0) {
		for(i=g_na;i>0;i--) g_a[i]=g_a[i-1];
		g_a[0] = g_b[0]; g_na++;
		for(i=0;i<g_nb-1;i++) g_b[i]=g_b[i+1];
		g_nb--;
	}
}
static void push_ba(void) {
	int i;
	if (g_na > 0) {
		for(i=g_nb;i>0;i--) g_b[i]=g_b[i-1];
		g_b[0] = g_a[0]; g_nb++;
		for(i=0;i<g_na-1;i++) g_a[i]=g_a[i+1];
		g_na--;
	}
}

static int exec_op(char *op) {
	if (!strcmp(op,"sa")) swap_top(g_a,g_na);
	else if (!strcmp(op,"sb")) swap_top(g_b,g_nb);
	else if (!strcmp(op,"ss")) { swap_top(g_a,g_na); swap_top(g_b,g_nb); }
	else if (!strcmp(op,"pa")) push_ab();
	else if (!strcmp(op,"pb")) push_ba();
	else if (!strcmp(op,"ra")) rotate(g_a,g_na);
	else if (!strcmp(op,"rb")) rotate(g_b,g_nb);
	else if (!strcmp(op,"rr")) { rotate(g_a,g_na); rotate(g_b,g_nb); }
	else if (!strcmp(op,"rra")) rev_rotate(g_a,g_na);
	else if (!strcmp(op,"rrb")) rev_rotate(g_b,g_nb);
	else if (!strcmp(op,"rrr")) { rev_rotate(g_a,g_na); rev_rotate(g_b,g_nb); }
	else return 0;
	return 1;
}

int main(int argc, char **argv) {
	int i, n;
	char line[64];

	if (argc < 2) return 0;
	n = argc - 1;
	g_a = (int*)malloc(sizeof(int)*n*2);
	g_b = (int*)malloc(sizeof(int)*n*2);
	g_na = n; g_nb = 0;
	for (i=0;i<n;i++) g_a[i] = atoi(argv[i+1]);

	while (fgets(line, sizeof(line), stdin)) {
		line[strcspn(line, "\r\n")] = 0;
		if (line[0] && !exec_op(line)) {
			fprintf(stderr, "Error\n"); free(g_a); free(g_b); return 1;
		}
	}
	if (g_nb != 0) { printf("KO\n"); free(g_a); free(g_b); return 0; }
	for (i=0;i<g_na-1;i++) {
		if (g_a[i] > g_a[i+1]) { printf("KO\n"); free(g_a); free(g_b); return 0; }
	}
	printf("OK\n");
	free(g_a); free(g_b);
	return 0;
}
