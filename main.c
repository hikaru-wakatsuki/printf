/* ************************************************************************** */
/*                                                                            */
/*   main.c - simple visual tester for ft_printf                              */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

/*
** 42 の ft_printf をリンクすることを想定
** あなたのプロジェクトのヘッダに合わせて include を変えてください。
*/
// #include "ft_printf.h"
int ft_printf(const char *fmt, ...);

/* ANSI Color */
#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"

/*
** 視覚的に分かりやすいテストマクロ
** label: テスト名
** fmt  : フォーマット文字列
** ...  : 可変長引数（ft_printf / printf にそのまま渡す）
**
** ※ 変換指定子がないフォーマット（"%%" だけなど）は TEST_NOARG を使う
*/

/* 引数あり用 */
#define TEST(label, fmt, ...)                                              \
    do {                                                                   \
        int r1, r2;                                                        \
        printf("\n%s========== %s ==========%s\n", CYAN, label, RESET);    \
                                                                           \
        /* printf の結果 */                                               \
        printf("  printf   : |");                                          \
        fflush(stdout);                                                    \
        r1 = printf(fmt, __VA_ARGS__);                                     \
        printf("| (ret = %d)\n", r1);                                      \
                                                                           \
        /* ft_printf の結果 */                                            \
        printf("  ft_printf: |");                                          \
        fflush(stdout);                                                    \
        r2 = ft_printf(fmt, __VA_ARGS__);                                  \
        printf("| (ret = %d)\n", r2);                                      \
                                                                           \
        if (r1 == r2)                                                      \
            printf("  %sOK: return value is same.%s\n", GREEN, RESET);     \
        else                                                               \
            printf("  %sNG: return value is different!%s\n", RED, RESET);  \
    } while (0)

/* 引数なし用（"%%" など） */
#define TEST_NOARG(label, fmt)                                             \
    do {                                                                   \
        int r1, r2;                                                        \
        printf("\n%s========== %s ==========%s\n", CYAN, label, RESET);    \
                                                                           \
        printf("  printf   : |");                                          \
        fflush(stdout);                                                    \
        r1 = printf(fmt);                                                  \
        printf("| (ret = %d)\n", r1);                                      \
                                                                           \
        printf("  ft_printf: |");                                          \
        fflush(stdout);                                                    \
        r2 = ft_printf(fmt);                                               \
        printf("| (ret = %d)\n", r2);                                      \
                                                                           \
        if (r1 == r2)                                                      \
            printf("  %sOK: return value is same.%s\n", GREEN, RESET);     \
        else                                                               \
            printf("  %sNG: return value is different!%s\n", RED, RESET);  \
    } while (0)

int main(void)
{
    int   x = 42;
    char *null_str = NULL;

    /* 文字 */
    TEST("char simple",           "c: %c", 'A');
    TEST("char null-ish",         "c: %c end", 0);

    /* 文字列 */
    TEST("string basic",          "s: %s", "hello");
    TEST("string empty",          "s: '%s'", "");
    TEST("string NULL",           "s: %s", null_str);

    /* ポインタ */
    TEST("pointer basic",         "p: %p", &x);
    TEST("pointer NULL",          "p: %p", (void *)0);

    /* 整数（符号付き） */
    TEST("int positive",          "d: %d", 42);
    TEST("int negative",          "d: %d", -42);
    TEST("int zero",              "d: %d", 0);
    TEST("int INT_MAX",           "d: %d", INT_MAX);
    TEST("int INT_MIN",           "d: %d", INT_MIN);

    /* 整数（符号なし） */
    TEST("unsigned basic",        "u: %u", 42u);
    TEST("unsigned big",          "u: %u", (unsigned int)UINT_MAX);

    /* 16進数 */
    TEST("hex lower",             "x: %x", 0x1234abcd);
    TEST("hex upper",             "X: %X", 0x1234ABCD);
    TEST("hex zero",              "x: %x", 0);

    /* パーセント表示 */
    TEST_NOARG("percent only",    "%%");
    TEST("percent with text",     "val=%% and %d", 42);

    /* 幅・精度・フラグのテスト例 */
    TEST("width right",           "|%10d|", 123);
    TEST("width left",            "|%-10d|", 123);
    TEST("zero flag",             "|%010d|", 123);
    TEST("precision int",         "|%.5d|", 123);
    TEST("precision string",      "|%.5s|", "abcdefg");
    TEST("mix flags",             "|%#08x|", 42);

    /* 複雑なフォーマット */
    TEST("mix all",
        "char=%c, str=%s, ptr=%p, d=%d, u=%u, x=%x, X=%X, %%\n",
        'Z', "test", &x, -123, 123u, 0x2a, 0x2a);

    return 0;
}
