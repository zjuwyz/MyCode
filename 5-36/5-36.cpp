//5-36 复数四则运算   (15分)
//本题要求编写程序，计算2个复数的和、差、积、商。
//
//输入格式：
//输入在一行中按照a1 b1 a2 b2的格式给出2个复数C1=a1+b1i和C2=a2+b2i的实部和虚部。题目保证C2不为0。
//
//输出格式：
//分别在4行中按照(a1+b1i) 运算符 (a2+b2i) = 结果的格式顺序输出2个复数的和、差、积、商，数字精确到小数点后1位。
//如果结果的实部或者虚部为0，则不输出。如果结果为0，则输出0.0。
//
//输入样例1：
//2 3.08 -2.04 5.06
//
//输出样例1：
//(2.0+3.1i) + (-2.0+5.1i) = 8.1i
//(2.0+3.1i) - (-2.0+5.1i) = 4.0-2.0i
//(2.0+3.1i) * (-2.0+5.1i) = -19.7+3.8i
//(2.0+3.1i) / (-2.0+5.1i) = 0.4-0.6i
//
//输入样例2：
//1 1 -1 -1.01	
//
//输出样例2：
//(1.0+1.0i) + (-1.0-1.0i) = 0.0
//(1.0+1.0i) - (-1.0-1.0i) = 2.0+2.0i
//(1.0+1.0i) * (-1.0-1.0i) = -2.0i
//(1.0+1.0i) / (-1.0-1.0i) = -1.0

#include <stdio.h>
#define ZERO 0.05;

struct cplx {
	double re;
	double im;
};

int isZero(double x) {
	if (x < 0) x = -x;
	return x < ZERO;
}

void putNum(struct cplx z) {
	if (isZero(z.re)) {
		if (isZero(z.im)) {
			printf("0.0");
		}
		else printf("%.1lfi", z.im);
	}
	else {
		printf("%.1lf", z.re);
		if (!isZero(z.im)) {
			printf("%+.1lfi", z.im);
		}
	}
}
void putLine(struct cplx z1, char c, struct cplx z2, struct cplx z3) {
	printf("(%.1lf%+.1lfi)", z1.re, z1.im);
	printf(" %c ", c);
	printf("(%.1lf%+.1lfi)", z2.re, z2.im);
	printf(" = ");
	putNum(z3); printf("\n");
}

struct cplx add(struct cplx z1, struct cplx z2) {
	struct cplx ans;
	ans.re = z1.re + z2.re;
	ans.im = z1.im + z2.im;
	return ans;
}

struct cplx minus(struct cplx z1, struct cplx z2) {
	struct cplx ans;
	ans.re = z1.re - z2.re;
	ans.im = z1.im - z2.im;
	return ans;
}

struct cplx product(struct cplx z1, struct cplx z2) {
	struct cplx ans;
	ans.re = z1.re * z2.re - z1.im * z2.im;
	ans.im = z1.re * z2.im + z2.re * z1.im;
	return ans;
}

struct cplx conj(struct cplx z) {
	struct cplx ans;
	ans.re = z.re;
	ans.im = -z.im;
	return ans;
}

struct cplx devide(struct cplx z1, struct cplx z2) {
	struct cplx ans;
	double denominator = z2.re * z2.re + z2.im * z2.im;
	struct cplx numerator = product(z1, conj(z2));
	ans.re = numerator.re / denominator;
	ans.im = numerator.im / denominator;
	return ans;
}

int main() {
	struct cplx z1, z2;
	scanf("%lf%lf%lf%lf", &z1.re, &z1.im, &z2.re, &z2.im);
	putLine(z1, '+', z2, add(z1, z2));
	putLine(z1, '-', z2, minus(z1, z2));
	putLine(z1, '*', z2, product(z1, z2));
	putLine(z1, '/', z2, devide(z1, z2));
	return 0;
}

